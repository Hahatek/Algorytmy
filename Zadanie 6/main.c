#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {

	lista head = NULL;
	lista head_sentinel = 0;
	add_first_element(&head_sentinel, INT_MAX);
	bool is_running = true;

	while (is_running) {
		// deklaracja zmiennych
		int choice;
		int number;
		int new_number;
		printf("Enter number of elements: \n");
		printf("1. Add element sort list \n");
		printf("2. Find element sort list \n");
		printf("3. Delete find element sort list \n");
		printf("4. Print first element \n");
		printf("5. Print last element \n");
		printf("6. Add element sort list with sentinel \n");
		printf("7. Find element sort list with sentinel \n");
		printf("8. Delete find element sort list with sentinel \n");
		printf("9. Print first element with sentinel\n");
		printf("10. Print last element with sentinel\n");
		printf("0. Exit \n");
		scanf("%d", &choice);


		switch (choice) {
		case 1:
			printf("Enter the number you want to add to the list: \n");
			scanf("%d", &number);
			add_element_sort_list(&head, number);
			display_the_contents_of_the_list(head);
			break;
		case 2:
			printf("Enter the number you want to find: \n");
			scanf("%d", &number);
			find_element_sort_list(head, number);
			display_the_contents_of_the_list(head);
			break;
		case 3:
			display_the_contents_of_the_list(head);
			printf("Enter the number you want to remove: \n");
			scanf("%d", &number);
			delete_find_element_sort_list(&head, number);
			display_the_contents_of_the_list(head);
			break;
		case 4:
			display_the_contents_of_the_list(head);
			print_first_element(head);
			break;
		case 5:
			display_the_contents_of_the_list(head);
			print_last_element(head);
			break;
		case 6:
			printf("Enter the number you want to add to the list with sentinel: \n");
			scanf("%d", &number);
			add_element_sort_list_with_sentinel(&head_sentinel, number);
			display_the_contents_of_the_list(head_sentinel);
			break;
		case 7:
			printf("Enter the number you want to find: \n");
			scanf("%d", &number);
			find_element_sort_list_with_sentinel(head_sentinel, number);
			display_the_contents_of_the_list(head_sentinel);
			break;
		case 8:
			display_the_contents_of_the_list(head);
			printf("Enter the number you want to remove: \n");
			scanf("%d", &number);
			delete_find_element_sort_list_with_sentinel(&head_sentinel, number);
			display_the_contents_of_the_list(head_sentinel);
			break;
		case 9:
			display_the_contents_of_the_list(head_sentinel);
			print_first_element_with_sentinel(head_sentinel);
			break;
		case 10:
			display_the_contents_of_the_list(head_sentinel);
			print_last_element_with_sentinel(head_sentinel);
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

