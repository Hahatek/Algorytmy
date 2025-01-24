#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct sort{
    int porownanie;
    int przestawienia;
}sort;

void copy(int tab1[], int tab2[], int size);
void showData(sort measurements[], int iterate, FILE *abc);
int randomNumber(int min, int max);

void bubbleSort(int tab[], int size, sort *measurement);
void byInsertingSort(int tab[], int size, sort *measurement);
void shellSort(int tab[], int size, sort *measurement);
void quickSort(int tab[], int start, int end, sort *measurement);
int partycja(int tab[], int start, int end, sort *measurement);

#endif //SORT_H
