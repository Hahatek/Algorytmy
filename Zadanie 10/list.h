#ifndef LIST_H
#define LIST_H

struct el {
	int key;
	struct el* next;
	struct el* prev;
};
typedef struct el elListy ;
typedef elListy* lista;

void add_first_element_cyclic_one_way(lista* list, int a);
void add_last_element_cyclic_one_way(lista* list, int a);
void delete_first_element_cyclic_one_way(lista* list);
void delete_last_element_cyclic_one_way(lista* list);
void find_the_specified_element_cyclic_one_way(lista list, int a);
void add_a_new_item_before_cyclic_one_way(lista* list, int a, int newElement);
void add_a_new_item_after_cyclic_one_way(lista list, int a, int newElement);
void remove_the_indicated_item_cyclic_one_way(lista* list, int a);
void display_the_contents_of_the_list_cyclic_one_way(lista head);
void display_the_contents_of_the_list_behind_cyclic_one_way(lista head);
void display_reverse_cyclic_one_way(lista list);

void add_first_element_cyclic_double_way(lista *list, int a);
void add_last_element_cyclic_double_way(lista *list, int a);
void delete_first_element_cyclic_double_way(lista *list);
void delete_last_element_cyclic_double_way(lista *list);
void find_the_specified_element_cyclic_double_way(lista list, int a);
void add_a_new_item_before_cyclic_double_way(lista *list, int a, int newElement);
void add_a_new_item_after_cyclic_double_way(lista list, int a, int newElement);
void remove_the_indicated_item_cyclic_double_way(lista *list, int a);
void display_the_contents_of_the_list_cyclic_double_way(lista list);
void display_reverse_cyclic_double_way(lista list);
#endif //LIST_H
