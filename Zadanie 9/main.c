#include <stdio.h>
#include <stdbool.h>
#include "list.h"
void menu_linked_list() {
    lista head = NULL;
    lista head_sentinel = 0;
    add_first_element(&head_sentinel, INT_MIN);
    add_last_element(&head_sentinel, INT_MAX);
    bool is_running = true;
    int choice, number, new_number, specified_element;

    while (is_running) {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Add first element\n");
        printf("2. Add last element\n");
        printf("3. Delete first element\n");
        printf("4. Delete last element\n");
        printf("5. Find specified element\n");
        printf("6. Add new item before specified element\n");
        printf("7. Add new item after specified element\n");
        printf("8. Remove specified item\n");
        printf("9. Display list contents\n");
        printf("10. Display list contents behind\n");
        printf("11. Add element to sorted list (with sentinel)\n");
        printf("12. Find element in sorted list (with sentinel)\n");
        printf("13. Delete element in sorted list (with sentinel)\n");
        printf("14. Print first element (with sentinel)\n");
        printf("15. Print last element (with sentinel)\n");
        printf("16. Display list contents sorted list\n");
        printf("0. Exit to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter the element to add at the beginning: ");
            scanf("%d", &number);
            add_first_element(&head, number);
            break;
        case 2:
            printf("Enter the element to add at the end: ");
            scanf("%d", &number);
            add_last_element(&head, number);
            break;
        case 3:
            delete_first_element(&head);
            break;
        case 4:
            delete_last_element(&head);
            break;
        case 5:
            printf("Enter the element to find: ");
            scanf("%d", &number);
            find_the_specified_element(head, number);
            break;
        case 6:
            printf("Enter the element before which to add: ");
            scanf("%d", &specified_element);
            printf("Enter the new element: ");
            scanf("%d", &new_number);
            add_a_new_item_before(&head, specified_element, new_number);
            break;
        case 7:
            printf("Enter the element after which to add: ");
            scanf("%d", &specified_element);
            printf("Enter the new element: ");
            scanf("%d", &new_number);
            add_a_new_item_after(head, specified_element, new_number);
            break;
        case 8:
            printf("Enter the item to remove: ");
            scanf("%d", &number);
            remove_the_indicated_item(&head, number);
            break;
        case 9:
            display_the_contents_of_the_list(head);
            break;
        case 10:
            display_the_contents_of_the_list_behind(head);
            break;
        case 11:
            printf("Enter the element to add to sorted list: ");
            scanf("%d", &number);
            add_element_sort_list_with_sentinel(&head_sentinel, number);
            break;
        case 12:
            printf("Enter the element to find in sorted list: ");
            scanf("%d", &number);
            find_element_sort_list_with_sentinel(head_sentinel, number);
            break;
        case 13:
            printf("Enter the element to delete from sorted list: ");
            scanf("%d", &number);
            delete_find_element_sort_list_with_sentinel(&head_sentinel, number);
            break;
        case 14:
            print_first_element_with_sentinel(head_sentinel);
            break;
        case 15:
            print_last_element_with_sentinel(head_sentinel);
            break;
        case 16:
            display_the_contents_of_the_list(head_sentinel);
            break;
        case 0:
            is_running = false;
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}

int main(void) {
    
    menu_linked_list();
    
    return 0;
}