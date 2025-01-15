#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	lista myList = NULL;

	add_new_element(&myList, 10, 2);
	add_new_element(&myList, 20, 5);
	add_new_element(&myList, 30, 3);

	display_the_contents_of_the_list(myList);

	change_priority(&myList, 10, 2137);
	display_the_contents_of_the_list(myList);

	lista highest = get_priority(&myList);
	printf("Pobrano element: %d (priorytet: %d)\n", highest->key, highest->priority);

	display_the_contents_of_the_list(myList);

	return 0;
}
