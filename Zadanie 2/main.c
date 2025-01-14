#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {

	lista head = NULL;


	bool is_running = true;

	while (is_running) {
		// deklaracja zmiennych
		int choice;
		int number;
		int new_number;
		printf("Enter number of elements: \n");
		printf("1. Add first element \n");
		printf("2. Add last element \n");
		printf("3. Delete first element \n");
		printf("4. Delete last element \n");
		printf("5. Find the specified element \n");
		printf("6. Add a new item before \n");
		printf("7. Add a new item after \n");
		printf("8. Remove the indicated item \n");
		printf("9. Display list front and back\n");
		printf("10. Remove number not recursively\n");
		printf("11. Remove number recursively\n");
		printf("0. Exit \n");
		scanf("%d", &choice);


		switch (choice) {
		case 1:
			printf("Enter the number you want to add to the list (first):\n");
			scanf("%d", &number);
			add_first_element(&head, number);
			display_the_contents_of_the_list(head);
			break;
		case 2:
			printf("Enter the number you want to add to the list (last):\n");
			scanf("%d", &number);
			add_last_element(&head, number);
			display_the_contents_of_the_list(head);
			break;
		case 3: // bubel
			delete_first_element(&head);
			display_the_contents_of_the_list(head);
			break;
		case 4:
			delete_last_element(&head);
			display_the_contents_of_the_list(head);
			break;
		case 5: // bubel z ostatnim
			printf("Enter the number you want to find:\n");
			scanf("%d", &number);
			find_the_specified_element(&head, number);
			display_the_contents_of_the_list(head);
			break;
		case 6:
			display_the_contents_of_the_list(head);
			printf("Enter the number before which you want to add a new number\n");
			scanf("%d", &number);
			printf("Enter the number you want to add to the list\n");
			scanf("%d", &new_number);
			add_a_new_item_before(&head, number, new_number);
			display_the_contents_of_the_list(head);
			break;
		case 7:
			display_the_contents_of_the_list(head);
			printf("Enter the number after which you want to add a new number\n");
			scanf("%d", &number);
			printf("Enter the number you want to add to the list\n");
			scanf("%d", &new_number);
			add_a_new_item_after(&head, number, new_number);
			display_the_contents_of_the_list(head);
			break;
		case 8:
			display_the_contents_of_the_list(head);
			printf("Enter the number after which you want to add a new number\n");
			scanf("%d", &number);
			remove_the_indicated_item(&head, number);
			display_the_contents_of_the_list(head);
			break;
		case 9:
			display_the_contents_of_the_list(head);
			display_the_contents_of_the_list_behind(head);
			break;
		case 10:
			display_the_contents_of_the_list(head);
			printf("Specify the number you want to remove not recursively:\n");
			scanf("%d", &number);
			non_recursive_delete_occurrence_of_the_indicated(&head, number);
			display_the_contents_of_the_list(head);
			break;
		case 11:
			display_the_contents_of_the_list(head);
			printf("Specify the number you want to remove recursively:\n");
			scanf("%d", &number);
			recursive_delete_occurrence_of_the_indicated(&head, number);
			display_the_contents_of_the_list(head);
			break;
		case 0:
			is_running= false;
			printf("Exiting...\n");
			break;
		default:
			printf("Wrong choice\n");
			break;
		}
	}



	return 0;
}
