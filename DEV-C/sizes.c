#include <stdio.h>
#include <stdlib.h>

int do_stuff();

typedef struct Person {
    int id;
    struct Person *mother;
} Person;

int main(void){
    Person p = {1};
    Person m = {2};
    printf("----Taille----\n");
    printf("La taille d'une structure <<Person>> en mémoire est de %ld octets\n", sizeof(Person));
    // printf("%ld\n", sizeof(p));

    p.mother = &m;
    // printf("%d\n", m.id);
    printf("----ID de la mère----\n");
    printf("ID : %d\n", p.mother->id);

    do_stuff();
}

int do_stuff() {
    int *list = malloc(3 * sizeof(int));
    if (list == NULL) {return 1;}
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL) {return 1;}
    list = tmp;
    list[3] = 4;
    printf("----Liste----\n");
    for (int i = 0; i < 4; i++) {
        printf("%i\n", list[i]);
    }

    free(list);
}


