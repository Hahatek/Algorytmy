#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int randomNumber(int min, int max) {
    return (rand() % (max - min + 1))+min;
}

void copy(int tab1[], int tab2[], int size) {
    for (int i = 0; i < size; i++) {
        tab1[i] = tab2[i];
    }
}

void showData(sort measurements[], int iterate, FILE *abc) {
    int minMod = measurements[0].przestawienia;
    int maxMod = measurements[0].przestawienia;
    int minPor = measurements[0].porownanie;
    int maxPor = measurements[0].porownanie;
    long long sumMod = 0;
    long long sumPor = 0;
    int i;

    for (i = 0; i < iterate; i++){
    sumMod += measurements[i].przestawienia;
    sumPor += measurements[i].porownanie;

    if (measurements[i].przestawienia > maxMod) {
        maxMod = measurements[i].przestawienia;
    }
    if (measurements[i].przestawienia < minMod) {
        minMod = measurements[i].przestawienia;
    }
    if (measurements[i].porownanie > maxPor) {
        maxPor = measurements[i].porownanie;
    }
    if (measurements[i].porownanie < minPor) {
        minPor = measurements[i].porownanie;
    }
    }

    double sredniaMod = sumMod/iterate;
    double sredniaPor = sumPor/iterate;

    printf("Ilosc porownan:      (MAX | MIN | SRE):   %d | %d | %.2lf\n", maxPor, minPor, sredniaPor);
    fprintf(abc,"Ilosc porownan:      (MAX | MIN | SRE):   %d | %d | %.2lf\n", maxPor, minPor, sredniaPor);
    printf("Ilosc modyfikacji:   (MAX | MIN | SRE):   %d | %d | %.2lf\n", maxMod, minMod, sredniaMod);
    fprintf(abc,"Ilosc modyfikacji:   (MAX | MIN | SRE):   %d | %d | %.2lf\n", maxMod, minMod, sredniaMod);
}

void bubbleSort(int tab[], int size, sort *measurement) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) { // pomijanie już posortowanych elementów
            measurement->porownanie++;
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                measurement->przestawienia += 3;
            }
        }
    }
}

void byInsertingSort(int tab[], int size, sort *measurement) {
    for (int i = 1; i < size; i++) {
        int temp = tab[i];
        int j = i - 1;
        measurement->porownanie++;
        while (j >= 0 && tab[j] > temp) {
            tab[j + 1] = tab[j];
            measurement->przestawienia++;
            j--;
            measurement->porownanie++;
        }
        tab[j + 1] = temp;
        measurement->przestawienia++;
    }
}

void shellSort(int tab[], int size, sort *measurement) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = tab[i];
            int j = i;
            while (j >= gap && tab[j - gap] > temp) {
                tab[j] = tab[j - gap];
                measurement->porownanie++;
                measurement->przestawienia++;
                j -= gap;
            }
            tab[j] = temp;
            measurement->przestawienia++;
        }
    }
}

int partycja(int tab[], int start, int end, sort *measurement) {
    int x = tab[end];
    int i = (start - 1);
    int temp, j;
    for (j = start; j < end; j++) {
        if (tab[j] <= x) {
            i++;
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            measurement->przestawienia += 3;
        }
        measurement->porownanie++;
    }
    temp = tab[i+1];
    tab[i+1] = tab[end];
    tab[end]  = temp;
    measurement->przestawienia += 3;
    return (i+1);
}

void quickSort(int tab[], int  start, int end, sort *measurement) {
    if (start < end) {
        int q = partycja(tab, start, end, measurement);
        quickSort(tab, start, q-1, measurement);
        quickSort(tab, q+1, end, measurement);
    }
}