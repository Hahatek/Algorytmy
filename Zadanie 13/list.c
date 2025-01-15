#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display_the_contents_of_the_list(lista head) {
	printf("\n");
	while (head != NULL)
	{
		printf("%d -> ", head->key);
		head = head->next;
	}
	printf("NULL\n\n");
}

void add_element(lista *list, int value,int priority) {
	lista new_node=(lista)malloc(sizeof(elListy));
	new_node->key = value;
	new_node->next = *list;
	new_node->priority = priority;
	*list = new_node;
}
void add_last_element(lista *list, int value, int priority) {
	while(*list!=NULL) {
		list=&((*list)->next);
	}
	add_element(list, value, priority);
}

void delete_element(lista *list) {
	lista temp_node=(lista)malloc(sizeof(elListy));
	if(*list!=NULL) {
		temp_node = *list;
		*list = temp_node->next;
		free(temp_node);
	}
}

void add_new_element(lista *list, int value, int priority) {
	if((*list)==NULL)
	{
		add_element(list, value, priority);
	}
	else {

		while((*list) != NULL && (*list)->priority >= priority)
		{

			list=&((*list)->next);
		}
		add_element(list, value, priority);
	}
}

lista get_priority(lista *list) {
    
	lista temp_node = NULL;
	if((*list) == NULL)
	{
		return NULL;
	}
	else {
		temp_node = *list;
		*list = temp_node->next;
		temp_node->next = NULL; // odłaczam element od listy
	}
	return temp_node;
}

void change_priority(lista *list, int value, int new_priority){
	if (*list == NULL) {
		printf("Lista jest pusta.\n");
		return;
	}

	lista *current_node = list;
	lista temp_node = NULL;

	while (*current_node != NULL && (*current_node)->key != value) {
		current_node = &((*current_node)->next);
	}

	if (*current_node == NULL) {
		printf("Element o wartości %d nie został znaleziony.\n", value);
		return;
	}

	temp_node = *current_node;
	*current_node = temp_node->next;

	temp_node->priority = new_priority;

	add_new_element(list, temp_node->key, temp_node->priority);

	free(temp_node);
}

