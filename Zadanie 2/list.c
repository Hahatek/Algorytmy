#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void add_first_element(lista* list, int a) {

	lista point = (lista)malloc(sizeof(elListy));
	point->key = a;
	point->next = *list;
	*list = point;
}

void add_last_element(lista* list, int a) {

	lista point = (lista)malloc(sizeof(elListy));
	point->key = a;
	point->next = NULL;

	while ((*list)) {
		list = &(*list)->next;
	}
	*list = point;
};

void delete_first_element(lista* list) {
	if (*list == NULL) {
		printf("List is empty\n");
		return;
	}
	lista temp = *list;
	*list = (*list)->next;


	free(temp);
}

void delete_last_element(lista* list) {
	if ((*list) == NULL) {
		printf("List is empty");
		return;
	}
	else {
		while ((*list)->next != NULL) {
			list = &(*list)->next;
		}
		*list = (*list)->next;
		free(*list);
	}
}

void find_the_specified_element(lista* list, int a) {

	if ((*list) == NULL) {
		printf("List is empty");
		return;
	}
	while ((*list) != NULL) {
		if ((*list)->key == a) {
			printf("The item was found");
			return;
		}
		list = &(*list)->next;

	}
	printf("The item wasn't found");
}

void add_a_new_item_before(lista* list, int a, int newElement) {

	if ((*list) == NULL) {
		printf("List is empty");
		return;
	}

	if ((*list)->key == a) {
		add_first_element(list, newElement);
		return;
	}

	lista point = (lista)malloc(sizeof(elListy));

	while ((*list)->next != NULL) {

		if ((*list)->next->key == a) {
			point->key = newElement;
			point->next = (*list)->next;
			(*list)->next = point;
			return;
		}
		list = &(*list)->next;
	}

}

void add_a_new_item_after(lista* list, int a, int newElement) {
	if ((*list) == NULL) {
		printf("List is empty");
		return;
	}

	if ((*list)->next == NULL) {
		add_first_element(list, a);
		return;
	}

	lista point = (lista)malloc(sizeof(elListy));

	while ((*list)->next != NULL) {
		if ((*list)->key == a) {
			point->key = newElement;
			point->next = (*list)->next;
			(*list)->next = point;
			return;
		}
		list = &(*list)->next;
	}

}

void remove_the_indicated_item(lista* list, int a) {

	if ((*list)->next == NULL) {
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


void display_the_contents_of_the_list_behind(lista head) {
	if (head == NULL) {
		printf("Lista jest pusta\n");
		return;
	}

	lista temp_node = head;
	int count = 0;

	while (temp_node != NULL) {
		count++;
		temp_node = temp_node->next;
	}

	printf("\n");

	for (int i = count - 1; i >= 0; i--) {
		temp_node = head;
		for (int j = 0; j < i; j++) {
			temp_node = temp_node->next;
		}
		printf("%d -> ", temp_node->key);
	}

	printf("NULL\n\n");
}

void non_recursive_delete_occurrence_of_the_indicated(lista* list, int a) {
	while (*list != NULL) {
		if ((*list)->key == a) {
			lista to_delete = *list;
			*list = (*list)->next;
			free(to_delete);

		}
		else {
			list = &(*list)->next;
		}
	}
}

int recursive_delete_occurrence_of_the_indicated(lista* list, int a) {
	if ((*list) == NULL) {
		return 0;
	}
	if ((*list)->key == a) {
		lista temp_node = *list;
		*list = (*list)->next;
		free(temp_node);
		return recursive_delete_occurrence_of_the_indicated(list, a);
	}
	return recursive_delete_occurrence_of_the_indicated(&(*list)->next, a);
}
