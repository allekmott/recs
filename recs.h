/* recs.h
 * Specifies user-driven record list operations
 * Created: 14 March 2016
 */

/* Print out version number */
void version();

/* Usage information (for n00bs) */
void usage(const char *cmd);

/* Test function for list writing */
void write_test();

/* Test function for list reading */
void read_test();

/* Function to allow for list creation;
 * user-terminated loop, prompts & stuff
 */
void create_list(const char *list_file){}