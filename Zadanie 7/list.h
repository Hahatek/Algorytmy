#ifndef LIST_H
#define LIST_H
#include <limits.h>

struct el {
    int key;
    struct el* next;
};
typedef struct el elListy ;
typedef elListy* lista;

// wyswietl zawartosc listy
void display_the_contents_of_the_list(lista head);
void add_first_element(lista* list, int a);
// z wartownikiem
void add_element_sort_list_with_sentinel(lista* list, int a);
void find_element_sort_list_with_sentinel(lista list, int a);
void delete_find_element_sort_list_with_sentinel(lista* list, int a);
int print_first_element_with_sentinel(lista list);
int print_last_element_with_sentinel(lista list);

void connect_two_lists(lista* p, lista* q);

#endif //LIST_H
