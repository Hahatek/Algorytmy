#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "kopiec.h"

void heapify(char** tab, int n, int i){
    int najwiekszy = i;
    int lewy_index = 2 * i + 1;
    int prawy_index = 2 * i + 2;

    if(lewy_index < n && strcmp(tab[lewy_index], tab[najwiekszy]) > 0){
        najwiekszy = lewy_index;
    }
    if(prawy_index < n && strcmp(tab[prawy_index], tab[najwiekszy]) > 0){
        najwiekszy = prawy_index;
    }
    if (najwiekszy != i){
        char* temp_znak = tab[i];
        tab[i] = tab[najwiekszy];
        tab[najwiekszy] = temp_znak;
        heapify(tab, n, najwiekszy);
    }
}

void hsort(char** tab, int n){
    for (int i = n/2-1;  i >= 0; i--){
        heapify(tab, n, i );
    }
    for (int i = n-1; i >= 0; i--){
        char* temp_znak = tab[0];
        tab[0] = tab[i];
        tab[i] = temp_znak;
        heapify(tab, i, 0);
    }
}

void wyswietlKopiec(char** tab, int n){

    for (int i = 0; i < n; i++) {
        printf("%s\n", tab[i]);
    }
}