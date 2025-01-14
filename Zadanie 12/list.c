#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void add_first_element_cyclic_one_way(lista *list, int a) {
	lista new_node = malloc(sizeof(lista));
	new_node->key = a;
	if (*list == NULL) {
		new_node->next = new_node;
		*list = new_node;
	} else {
		lista last = *list;
		while (last->next != *list) {
			last = last->next;
		}
		new_node->next = *list;
		last->next = new_node;
		*list = new_node;
	}
}

lista find_the_specified_element_cyclic_one_way(lista list, int a) {
	if (list == NULL) {
		printf("List is empty!");
		return NULL;
	}
	lista temp_node = list;
	do {
		if(temp_node->key == a) {
			return temp_node;
		}
		temp_node = temp_node->next;
	} while (temp_node != list);
	return NULL;

}
void remove_the_indicated_item_cyclic_one_way(lista *list, int a) {
	if (*list == NULL) {
		printf("List is empty!");
		return;
	}

	lista temp_node = *list;
	lista last_node = NULL;

	if ((*list)->key == a) {
		if ((*list)->next == *list) {
			delete_first_element_cyclic_one_way(list);
		}
	}
	do {
		last_node = temp_node;
		temp_node = temp_node->next;

		if (temp_node->key == a) {
			last_node->next = temp_node->next;
			free(temp_node);
			return;
		}
	} while (temp_node != *list);
}
void display_the_contents_of_the_list_cyclic_one_way(lista list) {
	if (list == NULL) {
		printf("List is empty!\n");
		return;
	}

	lista start = list;
	printf("\n");
	do {
		printf("%d -> ", list->key);
		list = list->next;
	} while (list != start);
	printf("NULL\n\n");
}
void delete_first_element_cyclic_one_way(lista *list) {
	if (*list == NULL) {
		printf("List is empty!");
		return;
	}
	if ((*list)->next == *list) {
		free(*list);
		*list = NULL;
		return;
	}
	lista temp_node = *list;
	lista last_node = *list;

	while (last_node->next != *list) {
		last_node = last_node->next;
	}

	last_node->next = temp_node->next;
	*list = temp_node->next;
	free(temp_node);
}
void delete_last_element_cyclic_one_way(lista *list) {
	if (*list == NULL) {
		printf("List is empty!");
		return;
	}
	if ((*list)->next == *list) {
		free(*list);
		*list = NULL;
		return;
	}

	lista temp_node = *list;
	lista last_node = NULL;

	while (temp_node->next != *list) {
		last_node = temp_node;
		temp_node = temp_node->next;
	}
	last_node->next = *list;
	free(temp_node);
}
void diff(lista* list1, lista* list2) {
	lista temp_node_b = *list2;
	lista temp_node;
	do {
		temp_node = find_the_specified_element_cyclic_one_way(*list1, temp_node_b->key);
		if (temp_node != NULL) {
			remove_the_indicated_item_cyclic_one_way(list1, temp_node_b->key);
		}
		temp_node_b = temp_node_b->next;
	} while (temp_node_b != (*list2));
}