#include <limits.h>

struct el {
    int key;
    struct el* next;
    struct el* prev;
};
typedef struct el elListy ;
typedef elListy* lista;

void add_first_element(lista* list, int a); 
void add_last_element(lista* list, int a);
void delete_first_element(lista* list); 
void delete_last_element(lista* list);
void find_the_specified_element(lista list, int a); 
void add_a_new_item_before(lista* list, int a, int newElement);
void add_a_new_item_after(lista list, int a, int newElement);
void remove_the_indicated_item(lista* list, int a);
void display_the_contents_of_the_list(lista head);
void display_the_contents_of_the_list_behind(lista head);

// z wartownikiem
void add_element_sort_list_with_sentinel(lista* list, int a);
void find_element_sort_list_with_sentinel(lista list, int a);
void delete_find_element_sort_list_with_sentinel(lista* list, int a);
void print_first_element_with_sentinel(lista list);
void print_last_element_with_sentinel(lista list);