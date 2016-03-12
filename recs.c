/* recs.c
 * RECord Search
 * Tool to simplify record hunts;
 * Organizes artists into alphabetized list,
 * allows for numerous traversal methods (in real-time).
 *
 * Created: 10 March 2016
 */

#include <stdio.h>

#include "list.h"

#define RECS_VERSION "0.0.4"

void version() {
	printf("recs v%s\n", RECS_VERSION);
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
	free_artists(head);
}

int main(int argc, char const *argv[]) {
	version();
	read_test();
	return 0;
}