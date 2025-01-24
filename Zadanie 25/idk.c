#include <stdio.h>
#include "idk.h"
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

void add_element(vertex *list, int value, int dystans){
    vertex new_node = (vertex)malloc(sizeof(idk));
    new_node->key = value;
    new_node->poprzednik = -1;         // Brak poprzednika na początku
    new_node->odwiedzony = false;
    new_node->next = *list;
    new_node->dystans = dystans;
    *list = new_node;
}

void add_new_element(vertex *list, int key, int dystans) {
    if (*list == NULL) {
        add_element(list, key, dystans);
        return;
    }

    vertex prev = NULL;
    vertex curr = *list;

    while (curr != NULL && curr->dystans <= dystans) {
        prev = curr;
        curr = curr->next;
    }

    vertex new_node = (vertex)malloc(sizeof(idk));
    new_node->key = key;
    new_node->poprzednik = -1;
    new_node->odwiedzony = false;
    new_node->dystans = dystans;

    if (prev == NULL) {
        new_node->next = *list;
        *list = new_node;
    } else {
        prev->next = new_node;
        new_node->next = curr;
    }
}

vertex find_element(vertex list, int value) {
    while (list != NULL) {
        if (list->key == value) {
            return list;  // Zwróć wskaźnik do elementu
        }
        list = list->next;
    }
    return NULL;  // Element nie został znaleziony
}

vertex get_priority(vertex *list){
    vertex temp_node = NULL;

    if((*list) == NULL)
    {
        printf("Lista jest pusta\n");
        return NULL;
    }
    else {
        temp_node = *list;
        *list = temp_node->next;
        temp_node->next = NULL; // odłączam element od listy
    }
    return temp_node;
}

void change_priority(vertex *list, int value, int new_dystans) {
    vertex *current = list;
    while (*current != NULL && (*current)->key != value) {
        current = &((*current)->next);
    }

    if (*current == NULL) {
        printf("Element o wartości %d nie został znaleziony.\n", value);
        return;
    }

    (*current)->dystans = new_dystans;

    vertex element = *current;
    *current = element->next;
    add_new_element(list, element->key, element->dystans);
}

void dijkstra(int start, vertex *list, int dystans[], int poprzednik[], krawendz* graf1, int V) {
    bool* odwiedzony = (bool*)malloc(V * sizeof(bool));
    for (int i = 0; i < V; i++) {
        odwiedzony[i] = false;
    }

    add_new_element(list, start, 0);
    dystans[start] = 0;

    while (*list != NULL) {
        vertex current = get_priority(list);
        int u = current->key;

        if (odwiedzony[u]) {
            free(current);
            continue;
        }

        odwiedzony[u] = true;

        krawendz neighbor = graf1[u];  // Dostęp do grafu przez graf1
        while (neighbor != NULL) {
            int v = neighbor->kierunek;
            int waga = neighbor->waga;

         if (!odwiedzony[v] && dystans[v] > dystans[u] + waga) {
                dystans[v] = dystans[u] + waga;
                poprzednik[v] = u;

                vertex existing = find_element(*list, v);
                if (existing != NULL) {
                    change_priority(list, v, dystans[v]);
                } else {
                    add_new_element(list, v, dystans[v]);
                }
            }
            neighbor = neighbor->next;
        }
        free(current);
    }

    free(odwiedzony);
}

void dodaj_krawedz(krawendz* graf1, int zrodlo, int cel, int waga) {
    krawendz nowa = (krawendz)malloc(sizeof(edge));
    nowa->kierunek = cel;
    nowa->waga = waga;
    nowa->next = graf1[zrodlo];
    graf1[zrodlo] = nowa;
}

void wyswietl_graf(krawendz* graf1, int V) {
    for(int i = 0; i < V; i++) {
        printf("Top %d: ", i);

        krawendz temp = graf1[i];
        while(temp != NULL) {
            printf("-> %d (waga: %d) ", temp->kierunek, temp->waga);
            temp = temp->next;
        }
        printf("\n");
    }
}

