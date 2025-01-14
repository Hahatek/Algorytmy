struct el {
	int key;
	struct el* next;
	struct el* prev;
};
typedef struct el elListy ;
typedef elListy* lista;

void add_first_element_cyclic_one_way(lista *list, int a);
lista find_the_specified_element_cyclic_one_way(lista list, int a);
void display_the_contents_of_the_list_cyclic_one_way(lista list);
void remove_the_indicated_item_cyclic_one_way(lista *list, int a);
void delete_first_element_cyclic_one_way(lista *list);
void delete_last_element_cyclic_one_way(lista *list);
void diff(lista* list1, lista* list2);