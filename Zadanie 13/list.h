struct el {
	int key;
	int priority;
	struct el* next;
};
typedef struct el elListy ;
typedef elListy* lista;

void display_the_contents_of_the_list(lista head);
void add_element(lista *list, int value,int priority);
void delete_element(lista *list);
void add_new_element(lista *list, int value, int priority);
lista get_priority(lista *list);
void change_priority(lista *list, int value, int new_priority);