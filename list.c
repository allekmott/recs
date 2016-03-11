/* list.c
 * Defines routines for insertion/deletion/traversal of both artist
 * and discography lists.
 * Created: 10 March 2016
 */

#include <stdio.h>
#include "list.h"

void print_discog(const struct album *head) {
	const struct album *a = head;
	while (a != NULL) {
		printf("%s\n", a->name);
		a = a->next;
	}
}


void print_artist(const struct artist *a) {
	printf("%s\n", a->name);
	print_discog(a->discog);
}