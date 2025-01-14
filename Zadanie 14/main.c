#include <stdio.h>
#include "tree.h"
int main(void) {
     starT root = NULL; // Inicjalizacja root jako NULL

    root = addNewNode(&root, 50);
    addNewNode(&root, 10);
    addNewNode(&root, 30);
    addNewNode(&root, 20);
    addNewNode(&root, 25);
    addNewNode(&root, 60);
    addNewNode(&root, 40);

    printf("Struktura drzewa:\n");
    printTree(root, 0, 'R');
    printf("\n");
    printf("\n");
    printf("Poprzednik 25: %d\n", nastepnik(root, 25));
    printf("\n");
    printf("\n");
    int y = maxnodes(root);
    printf("Max nodes: %d\n", y);
    printf("\n");
    printf("\n");
    int x = minnodes(root);
    printf("Min nodes: %d\n", x);
    printf("\n");
    printf("\n");
    printf("Search Node is 25:");
    starT znaleziony = searchNode(root, 25);
    if (znaleziony != NULL) {
        printf("Yes %d\n", znaleziony->key);
    } else {
        printf("No\n");
    }
    printf("Search Node is 11:");
    starT znalezionyA = searchNode(root, 11);
    if (znalezionyA != NULL) {
        printf("Yes %d\n", znalezionyA->key);
    } else {
        printf("No\n");
    }
    printf("\n");
    printf("\n");
    // Usuwanie różnych przypadków
    deleteNode(&root, 20); // Usuwanie liścia
    printf("Once removed 20:\n");
    printTree(root, 0, 'R');
    printf("\n");

    deleteNode(&root, 30); // Usuwanie węzła z jednym dzieckiem
    printf("Once removedu 30:\n");
    printTree(root, 0, 'R');
    printf("\n");

    deleteNode(&root, 50); // Usuwanie węzła z dwójką dzieci
    printf("Once removed 50 (root):\n");
    printTree(root, 0, 'R');
    printf("\n");


    return 0;
}