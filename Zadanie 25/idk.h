#ifndef ZADANIE_25_IDK_H
#define ZADANIE_25_IDK_H
#include <stdbool.h>

typedef struct vertex {
    int key;               // Numer wierzchołka
    int dystans;           // Najkrótsza odległość od źródła
    bool odwiedzony;       // Czy wierzchołek został odwiedzony
    int poprzednik;        // Poprzednik w ścieżce
    struct vertex* next;   // Następny wierzchołek w kolejce
} idk;

typedef idk* vertex;

typedef struct krawendz {
    int kierunek;  // do którego wierzchołka prowadzi krawędź
    int waga;       // waga/długość krawędzi
    struct krawendz* next;
} edge;

typedef edge* krawendz;

void add_element(vertex *list, int value, int dystans);

void add_new_element(vertex *list, int key, int dystans);

vertex find_element(vertex list, int value);

vertex get_priority(vertex *list);

void change_priority(vertex *list, int value, int new_dystans);

void dodaj_krawedz(krawendz* graf1, int zrodlo, int cel, int waga);

void wyswietl_graf(krawendz* graf1, int V);

void dijkstra(int start, vertex *list, int dystans[], int poprzednik[], krawendz* graf1, int V);



#endif //ZADANIE_25_IDK_H
