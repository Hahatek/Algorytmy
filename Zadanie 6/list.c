#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display_the_contents_of_the_list(lista head)
{
	printf("\n");
	while (head != NULL)
	{
		printf("%d -> ", head->key);
		head = head->next;
	}
	printf("NULL\n\n");
}

void add_first_element(lista* list, int a) {

	lista point = (lista)malloc(sizeof(elListy));
	point->key = a;
	point->next = *list;
	*list = point;
}



// bez wartownika
void add_element_sort_list(lista* list, int a) {
	// gdy lista pusta
	if((*list) == NULL) {
		lista point = (lista)malloc(sizeof(elListy));
		point->key = a;
		point->next = NULL;
		*list = point;
		return;
	}
	// gdy ma byc pierwszym elementem
	if(a < (*list)->key) {
		lista point = (lista)malloc(sizeof(elListy));
		point->key = a;
		point->next = *list;
		*list = point;
		return;
	}
	lista current = *list;
	while (current->next != NULL && current->next->key < a) {
		current = current->next;
	}

	lista point = (lista)malloc(sizeof(elListy));
	point->key = a;
	point->next = current->next;
	current->next = point;
}

void find_element_sort_list(lista list, int a) {
	if(list == NULL) {
		printf("List is empty");
	}
	while(list != NULL) {
		if(list->key == a) {
			printf("The item was found");
			return;
		}
		list = list->next;
	}
	printf("The item wasn't found");
}

void delete_find_element_sort_list(lista* list, int a) {
	if(list == NULL) {
		printf("List is empty");
	}
	while ((*list) != NULL) {

		if ((*list)->key == a) {
			*list = (*list)->next;
			return;
		}
		list = &(*list)->next;
	}
	free(*list);
}

void print_first_element(lista list) {
	if(list == NULL) {
		printf("List is empty");
		return;
	}
	printf("First element is: %d\n", list->key);
}

void print_last_element(lista list) {
	if(list == NULL) {
		printf("List is empty");
		return;
	}
	while(list != NULL) {
		if(list->next == NULL) {
			printf("Last element is: %d\n", list->key);
		}
		list = list->next;
	}
}

// z wartownikiem
void add_element_sort_list_with_sentinel(lista* list, int a) {
	while ((*list)->key < a)
	{
		list = &((*list)->next);
	}
	lista new_node = (lista)malloc(sizeof(elListy));;
	new_node->key = a;
	new_node->next = *list;
	*list = new_node;

}

void find_element_sort_list_with_sentinel(lista list, int a) {

	if(list == NULL) {
		printf("List is empty");
	}
	while(list->key <= a ) {
		if(list->key == a) {
			printf("The item was found");
			return;
		}
		list = list->next;
	}
	printf("The item wasn't found");
}

void delete_find_element_sort_list_with_sentinel(lista* list, int a) {
	if(list == NULL) {
		printf("List is empty");
	}
	while ((*list)->key <= a) {
		if ((*list)->key == a) {
			lista temp_node = *list;
			*list = (*list)->next;
			free(temp_node);
			return;
		}
		list = &(*list)->next;
	}

}

int print_first_element_with_sentinel(lista list) {
	if(list == NULL) {
		printf("List is empty");
		return -1;
	}
	printf("First element is: %d\n", list->key);
	return list->key;
}

int print_last_element_with_sentinel(lista list) {
	if(list == NULL) {
		printf("List is empty");
		return -1;
	}

	while(list->next->key != INT_MAX) {
		list = list->next;
	}
	printf("Last element is: %d\n", list->key);
	return list->key;
}