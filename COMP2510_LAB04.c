
/*
* lab04_mccaddend_v1.c
*
*    Created on: Feb 02, 2016
*        Author: Mccadden, Deric
* StudentNumber: A00751277
*/

#include <stdio.h>
#include <string.h>
#define LINESIZE 1024
#define CHECK(PRED) printf("%s ... %s\n",(PRED) ? "passed" : "FAILED", #PRED)

int get_words(const char prompt[], char word[], size_t n, const char eof[]);
int get_int(const char prompt[], int min, int max, int eof);

int main(void) {

	char prompt[] = "Input words";
	char word[6] = { 0 };
	size_t n = 11;
	char eof[] = "Exit";

	get_words(prompt, word, n, eof);
	printf("%s\n", word);

	char prompt2[] = "Input int:";
	int min = 1;
	int max = 9;
	int eof2 = 0;


	printf("%d\n", get_int(prompt2, min, max, eof2));

	return 0;
}


/* returns 1 if a word is succesfuly read and stored in the array of n characters
* otherwise returns 0 on end of file or when the user inputs the word specified
* by eof
*/

int get_words(const char prompt[], char word[], size_t n, const char eof[]) {
	char line[LINESIZE];

	while (1) {
		memset(word, 0, n);
		printf("%s\n", prompt);
		if (!fgets(line, LINESIZE, stdin)) {
			clearerr(stdin);
			break;
		}
		if (sscanf_s(line, "%s", word) == 1) {
			/* check for eof*/
			if (!strcmp(word, eof)) {
				break;
			}
			/* check for length */
			if (strlen(word) < n)
				return 1;
		}
	}
	return 0;
}



/* if an interger between min and max inclusive is sucessfuly read, it is
* returned; otherwise, the integer eof is returned when the user enters it on
* the end-of-file
* precondition: (min <= max) && (eof < min || eof > max)
*/
int get_int(const char prompt[], int min, int max, int eof) {
#define LINESIZE 1024
	char line[LINESIZE];
	int n;
	while (1) {
		printf("%s\n", prompt);
		if (!fgets(line, LINESIZE, stdin)) {
			clearerr(stdin);
			break;
		}
		if (sscanf_s(line, "%d", &n) == 1) {
			if (min <= n && n <= max) {
				return n;
			}
			else {
				break;
			}
		}
	}
	return eof;
}













