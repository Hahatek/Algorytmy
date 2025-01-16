#include <stdio.h>
#include "kopiec.h"

int main(void) {
    char* tab[] = {"cherry ", "apple", "banana", "mango", "grape"}; 
    int n = sizeof(tab) / sizeof(tab[0]); 

    printf("Tablica przed sortowaniem:\n");
    wyswietlKopiec(tab, n);

    hsort(tab, n);

    printf("\nTablica po sortowaniu:\n");
    wyswietlKopiec(tab, n);    return 0;
}