#include <stdio.h>
#include <stdlib.h>
#include <vector>

typedef struct Map {
    int height;
    int width;
} Map;

typedef struct Block {
    int pos_x;
    int pos_y;
    struct Block* top;
    struct Block* right;
    struct Block* bot;
    struct Block* left;
} Block;

map = std::vector<std::vector<Block>>;

typedef struct Player {
    struct Map* map;
    struct Block* position;
} Player;

/* class User {
    private:
        Password* password

}
*/

Map* get_map(int height, int width); // get map
Player* get_player(Map* map); // get player in map
void load_blocks(Map* map); // load blocks in map
void move(Player* player, char direction);  // move player in map
// direction sera 't', 'r', 'b', 'l' (top, right, bottom, left)

