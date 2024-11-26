#include <stdio.h>
void swap(int *a, int *b);

int main(int argc, char const *argv[]){
    int a = 1;
    int b = 2;

    printf("a = %i, b = %i.\n", a, b); // on print l'integer avant swap
    printf("adresse mémoire de a: %p\n", &a); // on print l'adresse mémoire
    printf("adresse mémoire de b: %p\n", &b);
    swap(&a, &b); // on fait appel à l'adresse mémoire pour swap
    printf("a = %i, b = %i.\n", a, b); // on print l'integer après swap
    printf("adresse mémoire de a: %p\n", &a);
    printf("adresse mémoire de b: %p\n", &b);

    int* pointer_a = &a;
    int a_value = *pointer_a;
    printf("valeur de a : %d\n", a_value);
    
    int a = 1;
    int *p_a = &a;

    int a_value = *p_a;
    printf("valeur de a : %p\n", a_value);
}

// attend des pointeurs pour swap
void swap(int *a, int *b) {
    printf("swapping\n");
    int temp = *a;
    *a = *b;
    *b = temp;
}
