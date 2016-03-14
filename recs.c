/* recs.c
 * RECord Search
 * Tool to simplify record hunts;
 * Organizes artists into alphabetized list,
 * allows for numerous traversal methods (in real-time).
 *
 * Created: 10 March 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "recs.h"
#include "list.h"

#define RECS_VERSION "0.0.5"

int main(int argc, char *argv[]) {
	version();

	char *list_file = "list.txt";
	struct artist *list;

	void (*op) (const char *);

	/* if you couldn't tell, I love this thing */
	int c;
	while ((c = getopt(argc, argv, "c")) != -1) {
		switch (c) {
			case 'c': op = create_list; break;
			case '?':
			default: usage(argv[0]);
		}
	}

	return 0;
}

void version() {
	printf("recs v%s\n", RECS_VERSION);
}

void usage(const char *cmd) {
	printf("Usage: %s [args]\n", cmd);
	exit(0);
}

void write_test() {
	struct artist head;
	head.name = "My Bloody Valentine";
	
	struct album headArtistFirstAlbum;
	headArtistFirstAlbum.name = "Isn't Anything";
	struct album headArtistSecondAlbum;
	headArtistSecondAlbum.name = "Loveless";
	headArtistSecondAlbum.next = NULL;
	headArtistFirstAlbum.next = &headArtistSecondAlbum;

	head.discog = &headArtistFirstAlbum;

	struct artist second;
	second.name = "Slowdive";

	struct album secondArtistFirstAlbum;
	secondArtistFirstAlbum.name = "Just For a Day";
	struct album secondArtistSecondAlbum;
	secondArtistSecondAlbum.name = "Souvlaki";
	secondArtistSecondAlbum.next = NULL;
	secondArtistFirstAlbum.next = &secondArtistSecondAlbum;

	second.discog = &secondArtistFirstAlbum;
	second.next = NULL;

	head.next = &second;

	print_artist(&head);
	print_artist(head.next);

	write_artists(&head, "lol.txt");
}

void read_test() {
	struct artist *head = read_artists("lol.txt");
	printf("\n\n");
	print_artists(head);
	printf("\n\n");
	free_artists(head);
}