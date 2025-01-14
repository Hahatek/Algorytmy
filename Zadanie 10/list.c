#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// JEDNOKIERUNKOWA
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
void add_last_element_cyclic_one_way(lista *list, int a) {
	lista new_node = malloc(sizeof(lista));
	new_node->key = a;
	if (*list == NULL) {
		new_node->next = new_node;
		*list = new_node;
	} else {
		lista last_node = *list;
		while (last_node->next != *list) {
			last_node = last_node->next;
		}
		new_node->next = *list;
		last_node->next = new_node;
	}
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
void find_the_specified_element_cyclic_one_way(lista list, int a) {
	if (list == NULL) {
		printf("List is empty!");
		return;
	}
	lista temp_node = list;
	do {
		if(temp_node->key == a) {
			printf("Element found!");
			return;
		}
		temp_node = temp_node->next;
	} while (temp_node != list);
	printf("Item not found!");
	return;

}
void add_a_new_item_before_cyclic_one_way(lista *list, int a, int newElement) {
	lista new_node = malloc(sizeof(lista));
	if (*list == NULL) {
		printf("List is empty!");
		return;
	}
	new_node->key = newElement;
	lista current_node = *list;
	lista prev_node = NULL;

	do {
		if (current_node->key == a) {
			if(current_node == *list) {
				add_first_element_cyclic_one_way(list, newElement);
			} else {
				new_node->next = current_node;
				prev_node->next = new_node;
			}
			return;
		}
		prev_node = current_node;
		current_node = current_node->next;
	} while (current_node != *list);

}
void add_a_new_item_after_cyclic_one_way(lista list, int a, int newElement) {
	lista new_node = malloc(sizeof(lista));
	if (list == NULL) {
		printf("List is empty!");
		return;
	}

	new_node->key = newElement;
	lista current_node = list;

	do {
		if (current_node->key == a) {
			new_node->next = current_node->next;
			current_node->next = new_node;
			return;
		}
		current_node = current_node->next;
	} while (current_node != list);
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
void display_reverse_cyclic_one_way(lista list) {
	if (list == NULL) {
		printf("List is empty!\n");
		return;
	}
	lista last = list;
	while (last->next != list) {
		last = last->next;
	}
	lista current = last;
	do {
		printf("%d -> ", current->key);
		lista prev = list;
		while (prev->next != current) {
			prev = prev->next;
		}
		current = prev;
	} while (current != last);

}

// DWUKIERUNKOWA

void add_first_element_cyclic_double_way(lista *list, int a) {
	lista new_node = malloc(sizeof(elListy));
	new_node->key = a;
	if (*list == NULL) {
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	} else {
		lista last = *list;
		while (last->next != *list) {
			last = last->next;
		}
		new_node->next = *list;
		(*list)->prev = new_node;
		last->next = new_node;
		new_node->prev = last;
		*list = new_node;
	}
}
void add_last_element_cyclic_double_way(lista *list, int a) {
    
    lista new_node = malloc(sizeof(elListy));
    new_node->key = a;
    if (*list == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *list = new_node;
    } else {
        lista last = (*list)->prev; 
        new_node->next = *list; 
        new_node->prev = last; 
        last->next = new_node; 
        (*list)->prev = new_node; 
    }
}
void delete_first_element_cyclic_double_way(lista *list) {
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
	last_node->prev = temp_node->prev;
	*list = temp_node->next;
	free(temp_node);
}
void delete_last_element_cyclic_double_way(lista *list) {
	if (*list == NULL) {
		printf("List is empty!");
		return;
	}
	if ((*list)->next == *list) {
		free(*list);
		*list = NULL;
		return;
	}

    lista last_node = (*list)->prev;
    lista new_last_node = last_node->prev;
    
    new_last_node->next = *list;
    (*list)->prev = new_last_node;
    
    free(last_node);
}
void find_the_specified_element_cyclic_double_way(lista list, int a) {
	if (list == NULL) {
		printf("List is empty!\n");
		return;
	}

	lista temp_node = list;
	do {
		if (temp_node->key == a) {
			printf("Element found!\n");
			return;
		}
		temp_node = temp_node->next;
	} while (temp_node != list);
}
void add_a_new_item_before_cyclic_double_way(lista *list, int a, int newElement) {
	lista new_node = malloc(sizeof(lista));
	if (*list == NULL) {
		printf("List is empty!");
		return;
	}
	new_node->key = newElement;

	lista current_node = *list;
	lista prev_node = current_node->prev;

	do {
		if (current_node->key == a) {
			if(current_node == *list) {
				add_first_element_cyclic_double_way(list, newElement);
			} else {
				new_node->next = current_node;
				new_node->prev = prev_node;
				prev_node->next = new_node;
				current_node->prev = new_node;
			}
			return;
		}
		prev_node = current_node;
		current_node = current_node->next;
	} while (current_node != *list);

}
void add_a_new_item_after_cyclic_double_way(lista list, int a, int newElement) {
	lista new_node = malloc(sizeof(lista));
	if (list == NULL) {
		printf("List is empty!");
		return;
	}

	new_node->key = newElement;
	lista current_node = list;

	do {
		if (current_node->key == a) {
			new_node->next = current_node->next;
			new_node->prev = new_node;
			current_node->next = new_node;
			list->prev = new_node;
			return;
		}
		current_node = current_node->next;
	} while (current_node != list);
}
void remove_the_indicated_item_cyclic_double_way(lista *list, int a) {
	if (*list == NULL) {
		printf("List is empty!");
		return;
	}

	lista temp_node = *list;
	lista last_node = NULL;

	if ((*list)->key == a) {
		if ((*list)->next == *list) {
			delete_first_element_cyclic_double_way(list);
		}
	}
	do {
		last_node = temp_node;
		temp_node = temp_node->next;

		if (temp_node->key == a) {
			last_node->next = temp_node->next;
			last_node->prev = temp_node->prev;
			*list = temp_node->next;
			free(temp_node);
			return;
		}
	} while (temp_node != *list);
}
void display_the_contents_of_the_list_cyclic_double_way(lista list) {
	if (list == NULL) {
		printf("List is empty!\n");
		return;
	}

	lista start = list;
	printf("\n");
	do {
		printf("%d <-> ", list->key);
		list = list->next;
	} while (list != start);
	printf("NULL\n\n");
}
void display_reverse_cyclic_double_way(lista list) {
	if (list == NULL) {
		printf("List is empty!\n");
		return;
	}
	lista current = list->prev;
	do {
		printf("%d <-> ", current->key);
		current = current->prev;
	} while (current != list->prev);
}