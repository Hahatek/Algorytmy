
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display_the_contents_of_the_list(lista head)
{
	printf("\n");
	while (head != NULL && head->key != INT_MAX)
	{
		printf("%d -> ", head->key);
		head = head->next;
	}
// 	printf("NULL\n\n");
}
void add_first_element(lista* list, int a) {

	lista point = (lista)malloc(sizeof(elListy));
	point->key = a;
	point->next = *list;
	*list = point;
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

void connect_two_lists(lista* p, lista* q){
    if(*p == NULL){
        *p = *q;
        *q = NULL;
        return;
    }

    if(*q == NULL){
        return;
    }

    lista *last = p;
    lista curr_p = *p;
    lista curr_q = *q;

    while(curr_p && curr_q){
        if(curr_q->key < curr_p->key){
            lista start_q = curr_q;
            while(curr_q->next && curr_q->next->key < curr_p->key){
                curr_q = curr_q->next;
            }

            lista next_q = curr_q->next;
            curr_q->next = curr_p;
            *last = start_q;
            last = &(curr_q->next);
            curr_q = next_q;
        }else{
            last = &(curr_p->next);
            curr_p = curr_p->next;
        }
    }

    if(curr_q){
        *last = curr_q;
    }

    *q = NULL;
}
