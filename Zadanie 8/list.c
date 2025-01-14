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

elListy* find_element_sort_list_with_sentinel(lista list, int a) {
    // Jeśli lista jest pusta, zwróć NULL
    if (list == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    while (list->key <= a) {
        if (list->key == a) {
            printf("The item was found\n");
            return list;
        }
        list = list->next;

        if (list == NULL) {
            break;
        }
    }

    printf("The item wasn't found\n");
    return NULL; 
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

void delete_element(lista* list)
{
    if(*list!=NULL)
    {
       lista new_node=*list;
        *list=new_node->next;
        free(new_node);
    }
}

void compare(lista p, lista q, lista* uniqP, lista* uniqQ) {
    lista walker = p;
    lista walker2 = q;
    lista tmp = NULL;
    
    while (walker != NULL && walker->key != INT_MAX) {
        tmp = find_element_sort_list_with_sentinel(q, walker->key);
        if (tmp == NULL) {
            add_element_sort_list_with_sentinel(uniqP, walker->key);
        }
        walker = walker->next; 
    }

    // Przejście przez listę q
    while (walker2 != NULL && walker2->key != INT_MAX) {
        tmp = find_element_sort_list_with_sentinel(p, walker2->key);
        if (tmp == NULL) {
            add_element_sort_list_with_sentinel(uniqQ, walker2->key);
        }
        walker2 = walker2->next; 
    }
}