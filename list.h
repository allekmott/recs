/* list.h
 * Defines node struct (artist) for linked artist list, along with
 * node struct (album) for discography list. Declared also are routines
 * for insertion/deletion/traversal of the aforementioned.
 * Created: 10 March 2016
 */

#ifndef RECS_LIST_H
#define RECS_LIST_H


struct album {
	const char *name;
	struct album *next;
};

struct artist {
	const char *name;
	struct album *discog;
	struct artist *next;
};

/* Prints out entire discography list */
void print_discog(const struct album *head);

/* Prints artist's name, along with discography */
void print_artist(const struct artist *a);


#endif