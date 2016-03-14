/* list.h
 * Defines node struct (artist) for linked artist list, along with
 * node struct (album) for discography list. Declared also are routines
 * for insertion/deletion/traversal of the aforementioned.
 * Created: 10 March 2016
 */

#include <stdio.h>

#ifndef RECS_LIST_H
#define RECS_LIST_H


struct album {
	char *name;
	struct album *next;
};

struct artist {
	char *name;
	struct album *discog;
	struct artist *next;
};

/* Prints out entire discography list */
void print_discog(const struct album *head);

/* Prints out entire artist list */
void print_artists(const struct artist *head);

/* Prints artist's name, along with discography */
void print_artist(const struct artist *a);

/* Write entire artist list to file specified by filename */
int write_artists(const struct artist *head, const char *filename);

/* Write artist's discography to file (used by write_list) */
void write_discog(const struct album *discog, FILE *out);

/* Read artist list in from file
 * *!ALLOCATES HEAP MEMORY!*
 * free_artists call necessary.
 */
struct artist *read_artists(const char *filename);

/* Frees entire artist list */
void free_artists(struct artist *head);

/* Free artist struct (recursive) */
void free_artist(struct artist *a);

/* Frees entire album list (discography) */
void free_discog(struct album *discog);

/* Free album struct (recursive) */
void free_album(struct album *a);

#endif