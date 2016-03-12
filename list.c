/* list.c
 * Defines routines for insertion/deletion/traversal of both artist
 * and discography lists.
 * Created: 10 March 2016
 */

#include <stdio.h>
#include <stdlib.h>
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

void print_artists(const struct artist *head) {
	const struct artist *a = head;
	while (a != NULL) {
		print_artist(a);
		a = a->next;
	}
}

void print_artist(const struct artist *a) {
	printf("%s\n", a->name);
	print_discog(a->discog);
}

int write_artists(const struct artist *head, const char *filename) {
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

struct artist *read_artists(const char *filename) {
	printf("Reading artist list from %s...\n", filename);

	FILE *in = fopen(filename, "r");
	struct artist *head_artist = NULL;
	struct artist *latest_artist;

	struct album *discog = NULL;
	struct album *latest_album;
	
	struct artist *new_artist;
	struct album *new_album;

	char buf[100];
	while (fgets(buf, 100, in) != NULL) {

		/* pull name from buffer, remove whitespace */
		char *name = malloc(strlen(buf));
		strcpy(name, buf);
		name[strlen(buf) - 1] = '\0';

		switch(buf[0]) {
			case '-': /* album */
				/* remove hyphen */
				name++;

				printf("%s album: %s\n", latest_artist->name, name);
				new_album = malloc(sizeof(struct album));

				/* remove hyphen */
				new_album->name = name;
				new_album->next = NULL;

				if (discog == NULL)
					/* start of discog */
					discog = latest_album = new_album;
				else {
					/* next elem in discog */
					latest_album->next = new_album;
					latest_album = latest_album->next;
				}
				break;
			default: /* artist */
				printf("Reading artist: %s\n", name);
				/* new artist => new artist node, flush discog */

				new_artist = malloc(sizeof(struct artist));
				new_artist->name = name;

				/* next = null, not random bs */
				new_artist->next = NULL;

				if (head_artist == NULL) {
					/* first artist read */
					if (discog != NULL) {
						/* album read before first artist, formatting error */
						free_artist(new_artist);
						return NULL;
					}
					head_artist = latest_artist = new_artist;
				} else {
					/* guaranteed not to be first artist */
					latest_artist->next = new_artist;

					/* flush discog */
					latest_artist->discog = discog;
					discog = latest_album = NULL;

					/* move latest to new */
					latest_artist = latest_artist->next;
				}
		}
	}
	if (discog != NULL)
		latest_artist->discog = discog;
	
	return head_artist;
}

void free_artists(struct artist *head) {
	if (head == NULL)
		return;

	printf("Freeing artist list starting with %s\n", head->name);
	free_artist(head);
}

void free_artist(struct artist *a) {
	if (a == NULL)
		return;

	printf("Freeing artist %s\n", a->name);

	if (a->next != NULL)
		free_artist(a->next);

	free_discog(a->discog);
	free(a);
}

void free_discog(struct album *discog) {
	if (discog == NULL)
		return;

	printf("Freeing discography starting with %s\n", discog->name);
	free_album(discog);
}

void free_album(struct album *a) {
	if (a == NULL)
		return;

	printf("Freeing album %s\n", a->name);

	if (a->next != NULL)
		free_album(a->next);

	free(a);
}