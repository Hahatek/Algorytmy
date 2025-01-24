#include <stdio.h>
#include "idk.h"
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>


void menu() {
    printf("\n=== MENU ===\n");
    printf("1. Add edge to graph\n");
    printf("2. Display graph\n");
    printf("3. Find shortest paths (Dijkstra)\n");
    printf("4. Find shortest path between two points\n");
    printf("5. Exit\n");
    printf("Select option: ");
}

int main() {
    krawendz* graf;
    int choice;

    int V = 6;
    printf("Test graph with %d vertices\n", V);

    // Graph initialization
    graf = (krawendz*)malloc(V * sizeof(krawendz));
    for(int i = 0; i < V; i++) {
        graf[i] = NULL;
    }

    dodaj_krawedz(graf, 0, 1, 4);  
    dodaj_krawedz(graf, 0, 2, 3);  
    dodaj_krawedz(graf, 1, 2, 1);  
    dodaj_krawedz(graf, 1, 3, 2);  
    dodaj_krawedz(graf, 2, 3, 6);  
    dodaj_krawedz(graf, 2, 4, 2);  
    dodaj_krawedz(graf, 3, 4, 3); 
    dodaj_krawedz(graf, 3, 5, 1);  
    dodaj_krawedz(graf, 4, 5, 4);  

    // tablica Dijkstra
    int* distance = (int*)malloc(V * sizeof(int));
    int* predecessor = (int*)malloc(V * sizeof(int));
    vertex list = NULL;

    do {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int start, end, weight;
                printf("Enter start vertex (0-%d): ", V-1);
                scanf("%d", &start);
                printf("Enter end vertex (0-%d): ", V-1);
                scanf("%d", &end);
                printf("Enter edge weight: ");
                scanf("%d", &weight);

                if(start >= 0 && start < V && end >= 0 && end < V) {
                    dodaj_krawedz(graf, start, end, weight);
                    printf("Edge added!\n");
                } else {
                    printf("Invalid vertex numbers!\n");
                }
                break;
            }
            case 2: {
                wyswietl_graf(graf, V);
                break;
            }
            case 3: {
                int start;
                printf("Enter start vertex (0-%d): ", V-1);
                scanf("%d", &start);

                if(start >= 0 && start < V) {
                    // Initialize arrays before each Dijkstra run
                    for(int i = 0; i < V; i++) {
                        distance[i] = INT_MAX;
                        predecessor[i] = -1;
                    }
                    list = NULL;  // Reset priority list

                    dijkstra(start, &list, distance, predecessor, graf, V);

                    // Display results
                    printf("\nShortest paths from vertex %d:\n", start);
                    for(int i = 0; i < V; i++) {
                        if(distance[i] == INT_MAX) {
                            printf("To %d: no path\n", i);
                        } else {
                            printf("To %d: distance = %d, predecessor = %d\n",
                                   i, distance[i], predecessor[i]);
                        }
                    }
                } else {
                    printf("Invalid vertex number!\n");
                }
                break;
            }
            case 4: {
                int start, end;
                printf("Enter start vertex (0-%d): ", V-1);
                scanf("%d", &start);
                printf("Enter end vertex (0-%d): ", V-1);
                scanf("%d", &end);

                if(start >= 0 && start < V && end >= 0 && end < V) {
                    for(int i = 0; i < V; i++) {
                        distance[i] = INT_MAX;
                        predecessor[i] = -1;
                    }
                    list = NULL;

                    dijkstra(start, &list, distance, predecessor, graf, V);

                    // Display path from start to end
                    if(distance[end] == INT_MAX) {
                        printf("No path exists between these vertices!\n");
                    } else {
                        printf("\nShortest path from %d to %d:\n", start, end);
                        printf("Path length: %d\n", distance[end]);
                        printf("Path: ");

                        int path[V];
                        int length = 0;

                        int current = end;
                        while(current != -1) {
                            path[length++] = current;
                            current = predecessor[current]; // predecessor poprzednik
                        }

                        for(int i = length-1; i >= 0; i--) {
                            printf("%d", path[i]);
                            if(i > 0) printf(" -> ");
                        }
                        printf("\n");
                    }
                } else {
                    printf("Invalid vertex numbers!\n");
                }
                break;
            }
            case 5: {
                printf("Program ended!\n");
                break;
            }
            default: {
                printf("Invalid option!\n");
            }
        }
    } while(choice != 5);

    for(int i = 0; i < V; i++) {
        krawendz current = graf[i];
        while(current != NULL) {
            krawendz temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graf);
    free(distance);
    free(predecessor);

    return 0;
}