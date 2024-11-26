#include "quadruple_chained_list.h"

int main() {
    int height = 5, width = 5;

    // Création de la carte et initialisation des blocs
    Map* map = get_map(height, width);
    load_blocks(map);

    // Création du joueur et placement initial
    Player* player = get_player(map);

    // Exemple de déplacement
    move(player, 'r');  // Déplacement à droite
    move(player, 'r');  // Déplacement à droite
    move(player, 'r');  // Déplacement à droite
    move(player, 'b');  // Déplacement en bas

    // Libération de la mémoire (à compléter si nécessaire)
    free(player);
    free(map->blocks);
    free(map);

    return 0;
}

Map* get_map(int height, int width) {
    // logique height/width
    Map* map = malloc(sizeof(Map)); // Allocation de la carte en mémoire
    map->height = height; // Initialisation de la hauteur
    map->width = width; // Initialisation de la largeur

    // Allocation du tableau 2D de blocs
    map->blocks = malloc(height * sizeof(Block*)); // Tableau de pointeurs de blocs (colonnes)
    // Allocation des lignes
    for (int i = 0; i < height; i++) {
        map->blocks[i] = malloc(width * sizeof(Block)); // Tableau de blocs (lignes)
    }

    return map;
}

void load_blocks(Map* map) {
    int height = map->height; // Récupération de la hauteur
    int width = map->width; // Récupération de la largeur

    // Création et liaison des blocs
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            Block* block = &map->blocks[x][y]; // Récupération du bloc
            block->pos_x = x; // Initialisation de la position x
            block->pos_y = y; // Initialisation de la position y

            // Liaison des blocs voisins
            block->top = (x > 0) ? &map->blocks[x - 1][y] : NULL; // Bloc du haut
            block->bot = (x < height - 1) ? &map->blocks[x + 1][y] : NULL; // Bloc du bas
            block->left = (y > 0) ? &map->blocks[x][y - 1] : NULL; // Bloc de gauche
            block->right = (y < width - 1) ? &map->blocks[x][y + 1] : NULL; // Bloc de droite
        }
    }
}

Player* get_player(Map* map) {
    // instance Player
    Player* player = malloc(sizeof(Player));
    player->map = map;
    // player.position = somewhere on the map
    player->position = &map->blocks[0][0];
    return player;
}

void move(Player* player, char direction) {
    Block* current = player->position; // Bloc actuel du joueur

    switch (direction) {
        case 't':  // Move top
            if (current->top != NULL) {
                player->position = current->top;
                printf("Moved to (%d, %d)\n", player->position->pos_x, player->position->pos_y);
            } else {
                printf("Cannot move up!\n");
            }
            break;
        case 'r':  // Move right
            if (current->right != NULL) {
                player->position = current->right;
                printf("Moved to (%d, %d)\n", player->position->pos_x, player->position->pos_y);
            } else {
                printf("Cannot move right!\n");
            }
            break;
        case 'b':  // Move bottom
            if (current->bot != NULL) {
                player->position = current->bot;
                printf("Moved to (%d, %d)\n", player->position->pos_x, player->position->pos_y);
            } else {
                printf("Cannot move down!\n");
            }
            break;
        case 'l':  // Move left
            if (current->left != NULL) {
                player->position = current->left;
                printf("Moved to (%d, %d)\n", player->position->pos_x, player->position->pos_y);
            } else {
                printf("Cannot move left!\n");
            }
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}
