#include <stdio.h>

float average(int length, int array[]);

int main (void) {
    int n = 5;
    int scores[n];
    
    // size_t = si on remplace le int par ça, alors on attend une valeur de sizeof
    for (int i = 0; i < n; i++) {
        scores[i] = i;
    }
    printf("Average: %.1f\n", average(n, scores)); // %.1f float 1 chiffre après la virgule
}

float average(int length, int array[]) {
    int sum = 0;

    for (size_t i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum/length;
}