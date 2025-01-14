#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
    lista head = (lista)malloc(sizeof(elListy));
    head->key = INT_MAX; // Wartownik
    head->next = NULL;

    int choice, value;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Add element (sorted)\n");
        printf("2. Display list\n");
        printf("3. Find element\n");
        printf("4. Delete element\n");
        printf("5. Print first element\n");
        printf("6. Print last element\n");
        printf("7. Compare two lists\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                add_element_sort_list_with_sentinel(&head, value);
                printf("Element added.\n");
                break;

            case 2:
                printf("List contents: \n");
                display_the_contents_of_the_list(head);
                break;

            case 3:
                printf("Enter value to find: ");
                scanf("%d", &value);
                if (find_element_sort_list_with_sentinel(head, value) != NULL) {
                    printf("Element found.\n");
                } else {
                    printf("Element not found.\n");
                }
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete_find_element_sort_list_with_sentinel(&head, value);
                printf("Element deleted if it existed.\n");
                break;

            case 5:
                print_first_element_with_sentinel(head);
                break;

            case 6:
                print_last_element_with_sentinel(head);
                break;

            case 7: {
                lista list1 = (lista)malloc(sizeof(elListy));
                lista list2 = (lista)malloc(sizeof(elListy));
                list1->key = INT_MAX; 
                list1->next = NULL;
                list2->key = INT_MAX; 
                list2->next = NULL;

                printf("Enter elements for list1 (-1 to stop): \n");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1) break;
                    add_element_sort_list_with_sentinel(&list1, value);
                }

                printf("Enter elements for list2 (-1 to stop): \n");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1) break;
                    add_element_sort_list_with_sentinel(&list2, value);
                }

                lista uniqList1 = (lista)malloc(sizeof(elListy));
                lista uniqList2 = (lista)malloc(sizeof(elListy));
                uniqList1->key = INT_MAX; // Wartownik
                uniqList1->next = NULL;
                uniqList2->key = INT_MAX; // Wartownik
                uniqList2->next = NULL;

                printf("Comparing lists...\n");
                compare(list1, list2, &uniqList1, &uniqList2);

                printf("Unique elements in list1: \n");
                display_the_contents_of_the_list(uniqList1);
                printf("\nUnique elements in list2: \n");
                display_the_contents_of_the_list(uniqList2);
                break;
            }

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    while (head->key != INT_MAX) {
        delete_element(&head);
    }
    free(head);

    return 0;
}

