#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"



int main(void) {
	lista head1 = NULL;
	lista head2 = NULL;

	add_first_element_cyclic_one_way(&head1, 1);
	add_first_element_cyclic_one_way(&head1, 2);
	add_first_element_cyclic_one_way(&head1, 3);
	add_first_element_cyclic_one_way(&head1, 4);
	add_first_element_cyclic_one_way(&head1, 5);

	add_first_element_cyclic_one_way(&head2, 1);
	add_first_element_cyclic_one_way(&head2, 2);
	add_first_element_cyclic_one_way(&head2, 3);
	add_first_element_cyclic_one_way(&head2, 2137);
	add_first_element_cyclic_one_way(&head2, 123);

	printf("Lista pierwsza: \n");
	display_the_contents_of_the_list_cyclic_one_way(head1);
	printf("\n");
	printf("Lista druga: \n");
	display_the_contents_of_the_list_cyclic_one_way(head2);

	diff(&head1, &head2);
	printf("Po wykonaniu funkcji: \n");
	display_the_contents_of_the_list_cyclic_one_way(head1);
	return 0;
}