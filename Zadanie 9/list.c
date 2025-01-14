#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdint.h>


void add_first_element(lista *list, int a) {
    lista temp_node = (lista) malloc(sizeof(elListy));
    temp_node->key = a;
    temp_node->next = *list;
    temp_node->prev = NULL;
    *list = temp_node;
}

void add_last_element(lista *list, int a) {
    lista temp_node = (lista) malloc(sizeof(elListy));;
    temp_node->key = a;
    temp_node->next = NULL;
    while (*list != NULL) {
        list = &(*list)->next;
    }
    *list = temp_node;
    temp_node->prev = *list;

}

void delete_first_element(lista *list) {
    if (*list == NULL) {
        printf("List is empty\n");
        return;
    }
    lista temp_node = *list;
    *list = (*list)->next;
    (*list)->prev = NULL;
    free(temp_node);
 
}

void delete_last_element(lista *list) {
    if (*list == NULL) {
        printf("List is empty\n");
        return;
    }

    while ((*list)->next != NULL) {
        list = &(*list)->next;
    }
    free(*list);
    *list = 0;
}

void find_the_specified_element(lista list, int a) {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    while (list != NULL) {
        if (list->key == a) {
            printf("Element found");
            return;
        }

        list = list->next;
    }
    printf("Element not found");
}

void add_a_new_item_before(lista *list, int a, int newElement) {
    if(*list == NULL) {
        printf("List is empty");
        return;
    }
    lista new_node = malloc(sizeof(elListy));
    while(*list != NULL) {
        if((*list)->key == a) {
            new_node->key = newElement;
            new_node->next = *list;
            (*list)->prev = new_node;
            *list = new_node;
            return;
        }
        list = &(*list)->next;
    }
    printf("element nie istnieje");
}

void add_a_new_item_after(lista list, int a, int newElement) {
    if(list == NULL) {
        printf("List is empty");
        return;
    }
    lista new_node = malloc(sizeof(elListy));
    while(list != NULL) {
        if(list->key == a) {
            new_node->key = newElement;
            new_node->next = list->next;
            new_node->prev = list;
            list->next = new_node;
            return;
        }
        list = list->next;
    }
    printf("element nie istnieje");
}

void remove_the_indicated_item(lista *list, int a) {
if(*list == NULL) {
    printf("List is empty");
    return;
}
    lista temp_node = *list;
    while(temp_node != NULL) {
        if(temp_node->key == a) {
            if(temp_node->prev == 0){
                delete_first_element(list);
                return;
            }
            else if(temp_node->next == 0){
                delete_last_element(list);
                return;
            }else{
                temp_node->prev->next = temp_node->next;
                temp_node->next->prev = temp_node->prev;
                free(temp_node);
            }
            return;
        }
       temp_node = temp_node->next;
    }

    printf("element nie istnieje");
}

void display_the_contents_of_the_list(lista list) {
    printf("\n");
    while (list != NULL) {
        printf("%d <-> ", list->key);
        list = list->next;
    }
    printf("NULL\n\n");
}

void display_the_contents_of_the_list_behind(lista list){

}

// LISTA POSORTOWANA

void add_element_sort_list_with_sentinel(lista* list, int a) {
    lista new_node = (lista) malloc(sizeof(elListy));
    new_node->key = a;

    lista current = *list;
    while (current->next != NULL && current->next->key < a) {
        current = current->next;
    }

    new_node->next = current->next;
    new_node->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = new_node;
    }
    current->next = new_node;
}

void find_element_sort_list_with_sentinel(lista list, int a) {
    while (list->key <= a) {
        if (list->key == a) {
            printf("Element found");
            return;
        }
        list = list->next;
    }
    printf("Element not found!");
}
void delete_find_element_sort_list_with_sentinel(lista* list, int a) {
    if (*list == NULL) {
        printf("List is empty");
        return;
    }

    lista current = (*list)->next;
    while (current->key < a) {
        current = current->next;
    }
    (*list)->next = current->next;
    if (current->next != NULL) {
        current->next->prev = *list;
    }


    free(current);
}
void print_first_element_with_sentinel(lista list) {
    if (list->next == list) {
        printf("List is empty\n");
    } else {
        printf("First element: %d\n", list->next->key);
    }
}
void print_last_element_with_sentinel(lista list) {
    if(list == NULL) {
        printf("List is empty");
        return;
    }
    while(list->next->key < INT_MAX) {
        list = list->next;
    }
    printf("Last node is: %d", list->key);
}
