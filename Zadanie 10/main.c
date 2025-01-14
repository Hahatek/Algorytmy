#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void menu_cyclic_one_way() {
	lista head = NULL;
	bool is_running = true;
	int choice, number, new_number, specified_element;

	while (is_running) {
		printf("\n--- CYCLIC ONE-WAY LIST MENU ---\n");
		printf("1. Add first element\n");
		printf("2. Add last element\n");
		printf("3. Delete first element\n");
		printf("4. Delete last element\n");
		printf("5. Find specified element\n");
		printf("6. Add new item before specified element\n");
		printf("7. Add new item after specified element\n");
		printf("8. Remove specified item\n");
		printf("9. Display list contents\n");
		printf("10. Display list behind contents\n");
		printf("0. Exit to main menu\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			printf("Enter the element to add at the beginning: ");
			scanf("%d", &number);
			add_first_element_cyclic_one_way(&head, number);
			break;
		case 2:
			printf("Enter the element to add at the end: ");
			scanf("%d", &number);
			add_last_element_cyclic_one_way(&head, number);
			break;
		case 3:
			delete_first_element_cyclic_one_way(&head);
			break;
		case 4:
			delete_last_element_cyclic_one_way(&head);
			break;
		case 5:
			printf("Enter the element to find: ");
			scanf("%d", &number);
			find_the_specified_element_cyclic_one_way(head, number);
			break;
		case 6:
			printf("Enter the element before which to add: ");
			scanf("%d", &specified_element);
			printf("Enter the new element: ");
			scanf("%d", &new_number);
			add_a_new_item_before_cyclic_one_way(&head, specified_element, new_number);
			break;
		case 7:
			printf("Enter the element after which to add: ");
			scanf("%d", &specified_element);
			printf("Enter the new element: ");
			scanf("%d", &new_number);
			add_a_new_item_after_cyclic_one_way(head, specified_element, new_number);
			break;
		case 8:
			printf("Enter the item to remove: ");
			scanf("%d", &number);
			remove_the_indicated_item_cyclic_one_way(&head, number);
			break;
		case 9:
			display_the_contents_of_the_list_cyclic_one_way(head);
			break;
		case 10:
			display_reverse_cyclic_one_way(head);
			break;
		case 0:
			is_running = false;
			break;
		default:
			printf("Invalid choice. Try again.\n");
		}
	}
}

// Menu dla listy dwukierunkowej
void menu_cyclic_double_way() {
	lista head = NULL;
	bool is_running = true;
	int choice, number, new_number, specified_element;

	while (is_running) {
		printf("\n--- CYCLIC DOUBLE-WAY LIST MENU ---\n");
		printf("1. Add first element\n");
		printf("2. Add last element\n");
		printf("3. Delete first element\n");
		printf("4. Delete last element\n");
		printf("5. Find specified element\n");
		printf("6. Add new item before specified element\n");
		printf("7. Add new item after specified element\n");
		printf("8. Remove specified item\n");
		printf("9. Display list contents\n");
		printf("10. Display list behind contents\n");
		printf("0. Exit to main menu\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			printf("Enter the element to add at the beginning: ");
			scanf("%d", &number);
			add_first_element_cyclic_double_way(&head, number);
			break;
		case 2:
			printf("Enter the element to add at the end: ");
			scanf("%d", &number);
			add_last_element_cyclic_double_way(&head, number);
			break;
		case 3:
			delete_first_element_cyclic_double_way(&head);
			break;
		case 4:
			delete_last_element_cyclic_double_way(&head);
			break;
		case 5:
			printf("Enter the element to find: ");
			scanf("%d", &number);
			find_the_specified_element_cyclic_double_way(head, number);
			break;
		case 6:
			printf("Enter the element before which to add: ");
			scanf("%d", &specified_element);
			printf("Enter the new element: ");
			scanf("%d", &new_number);
			add_a_new_item_before_cyclic_double_way(&head, specified_element, new_number);
			break;
		case 7:
			printf("Enter the element after which to add: ");
			scanf("%d", &specified_element);
			printf("Enter the new element: ");
			scanf("%d", &new_number);
			add_a_new_item_after_cyclic_double_way(head, specified_element, new_number);
			break;
		case 8:
			printf("Enter the item to remove: ");
			scanf("%d", &number);
			remove_the_indicated_item_cyclic_double_way(&head, number);
			break;
		case 9:
			display_the_contents_of_the_list_cyclic_double_way(head);
			break;
		case 10:
			display_reverse_cyclic_double_way(head);
			break;
		case 0:
			is_running = false;
			break;
		default:
			printf("Invalid choice. Try again.\n");
		}
	}
}

// GEC3wne menu
int main(void) {
	bool is_running = true;
	int choice;

	while (is_running) {
		printf("\n--- MAIN MENU ---\n");
		printf("1. Cyclic One-Way List Operations\n");
		printf("2. Cyclic Double-Way List Operations\n");
		printf("0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			menu_cyclic_one_way();
			break;
		case 2:
			menu_cyclic_double_way();
			break;
		case 0:
			is_running = false;
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid choice. Try again.\n");
		}
	}
	return 0;
}