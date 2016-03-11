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

#define RECS_VERSION "0.0.1"

void version() {
	printf("recs v%s\n", RECS_VERSION);
}

int main(int argc, char const *argv[]) {
	version();
	return 0;
}