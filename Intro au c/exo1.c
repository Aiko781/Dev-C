#include "lib.h"

int main() {
    struct Person toto;
    toto.age = 21;
    // toto.name = 'Toto';
    // int toto.abc = 1; faux car pas dans la mémoire prévu pour la struct
    strcpy(toto.name, "Adrien");
    toto.lastname = "LE GOAT";

    printf("----Contenu Toto----\n");
    printf("%s %s a %d ans\n", toto.name, toto.lastname, toto.age);

    printf("----Pointeur Toto----\n");
    struct Person* toto_ptr = &toto;
    printf("%p\n", toto_ptr);
    // toto_ptr.age = 22; Marche pas car le pointeur vers la struct n'a pas d'âge
    // Mais cette syntaxe fonctionne;
    toto_ptr->age = 22;
    printf("----Age de l'entité----\n");
    printf("%d\n", toto_ptr->age); // Qu'on l'écrive comme ça ou comme en dessous c'est pareil
    printf("%d\n", toto.age);

    printf("----Adresses Toto----\n");
    printf("%p\n", &toto);
    printf("%p\n", &toto.name);

    printf("----Contenu Titi----\n");
    struct Person titi = {33, "toto", "skilipipapa"};
    printf("%s %s a %d ans\n", titi.name, titi.lastname, titi.age);

    printf("----Adresses Titi----\n");
    printf("%p\n", &titi);
    printf("%p\n", &titi.name);

    printf("----La boucle !----\n");
    for (int a=0; a<13; a++) {
        printf("%c", toto.name[a]);
    }
    printf("\n");
    printf("\nSize : %ld\n", sizeof(toto));

    struct Person people[3];
    struct Person *address_of_p = people;
    struct Person *p = people;

    // for(int i = 1; i < 4; i++) {
    //     printf("%p\n", address_of_p);
    //     address_of_p->id = i;
    //     address_of_p += 1;
    // }

    for (int y = 1; y < 4; y++) {
        printf("%p\n", p);
        struct Person p = people[y];
    }
}

