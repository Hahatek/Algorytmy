#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

lista list_p = 0;  // First list with sentinel
lista list_q = 0;  // Second list with sentinel

// Initialize sentinel lists
void initialize_sentinel_lists() {
    add_first_element(&list_p, INT_MAX);
    add_first_element(&list_q, INT_MAX);
}

// Menu for list p
void menu_list_p() {
    bool is_running = true;
    while (is_running) {
        int choice, number;
        
        printf("\n--- Menu for List P ---\n");
        printf("1. Add element to sorted list P\n");
        printf("2. Find element in sorted list P\n");
        printf("3. Delete element from sorted list P\n");
        printf("4. Print first element of list P\n");
        printf("5. Print last element of list P\n");
        printf("6. Display list P\n");
        printf("0. Return to main menu\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number to add: ");
                scanf("%d", &number);
                add_element_sort_list_with_sentinel(&list_p, number);
                display_the_contents_of_the_list(list_p);
                break;
            
            case 2:
                printf("Enter number to find: ");
                scanf("%d", &number);
                find_element_sort_list_with_sentinel(list_p, number);
                break;
            
            case 3:
                printf("Enter number to delete: ");
                scanf("%d", &number);
                delete_find_element_sort_list_with_sentinel(&list_p, number);
                display_the_contents_of_the_list(list_p);
                break;
            
            case 4:
                print_first_element_with_sentinel(list_p);
                break;
            
            case 5:
                print_last_element_with_sentinel(list_p);
                break;
            
            case 6:
                display_the_contents_of_the_list(list_p);
                break;
            
            case 0:
                is_running = false;
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

// Menu for list q
void menu_list_q() {
    bool is_running = true;
    while (is_running) {
        int choice, number;
        
        printf("\n--- Menu for List Q ---\n");
        printf("1. Add element to sorted list Q\n");
        printf("2. Find element in sorted list Q\n");
        printf("3. Delete element from sorted list Q\n");
        printf("4. Print first element of list Q\n");
        printf("5. Print last element of list Q\n");
        printf("6. Display list Q\n");
        printf("0. Return to main menu\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number to add: ");
                scanf("%d", &number);
                add_element_sort_list_with_sentinel(&list_q, number);
                display_the_contents_of_the_list(list_q);
                break;
            
            case 2:
                printf("Enter number to find: ");
                scanf("%d", &number);
                find_element_sort_list_with_sentinel(list_q, number);
                break;
            
            case 3:
                printf("Enter number to delete: ");
                scanf("%d", &number);
                delete_find_element_sort_list_with_sentinel(&list_q, number);
                display_the_contents_of_the_list(list_q);
                break;
            
            case 4:
                print_first_element_with_sentinel(list_q);
                break;
            
            case 5:
                print_last_element_with_sentinel(list_q);
                break;
            
            case 6:
                display_the_contents_of_the_list(list_q);
                break;
            
            case 0:
                is_running = false;
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

// Main menu to choose between lists and operations
int main(void) {
    // Initialize sentinel lists with INT_MAX as sentinel
    initialize_sentinel_lists();
    
    bool is_running = true;
    while (is_running) {
        int choice;
        
        printf("\n=== MAIN MENU ===\n");
        printf("1. Work with List P\n");
        printf("2. Work with List Q\n");
        printf("3. Connect Lists P and Q\n");
        printf("0. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                menu_list_p();
                break;
            
            case 2:
                menu_list_q();
                break;
            
            case 3:
                printf("Connecting Lists P and Q...\n");
                connect_two_lists(&list_p, &list_q);
                printf("Lists connected. Result in List P:\n");
                display_the_contents_of_the_list(list_p);
                break;
            
            case 0:
                is_running = false;
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}