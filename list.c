/* list.c
 * Defines routines for insertion/deletion/traversal of both artist
 * and discography lists.
 * Created: 10 March 2016
 */

#include <stdio.h>
#include <string.h>

#include "list.h"

void print_discog(const struct album *head) {
	const struct album *a = head;

	/* a == NULL @ end of list (null initially if no elements) */
	while (a != NULL) {
		printf("%s\n", a->name);
		a = a->next;
	}
}

void print_artist(const struct artist *a) {
	printf("%s\n", a->name);
	print_discog(a->discog);
}

int write_list(const struct artist *head, const char *filename) {
	printf("Writing artist list to %s...\n", filename);

	/* head = head of artist list */
	const struct artist *a = head;

	/* open output file, write */
	FILE *out = fopen(filename, "w");
	if (out == NULL)
		return -1;

	while (a != NULL) {
		printf("Writing %s and discog...\n", a->name);

		/* write artist's name */
		fprintf(out, "%s\n", a->name);

		/* write artist's discography */
		write_discog(a->discog, out);

		a = a->next;
	}

	/* error closing file */
	if (fclose(out) == EOF)
		return -1;

	return 0;
}

void write_discog(const struct album *discog, FILE *out) {
	/* discog head of album list (album list = discography) */
	const struct album *a = discog;

	/* keep track of # of bytes written */
	int written = 0;
	while (a != NULL) {
		/* fwrite string "-[album.name]" */
		fprintf(out, "-%s\n", a->name);
		a = a->next;
	}
}

