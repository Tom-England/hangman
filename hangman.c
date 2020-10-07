#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	// Seed the random number generator with current time
	srand(time(0));	
	
	// Declare words
	int wordCount = 2;
	const char *words[wordCount];
	words[0] = "test";
	words[1] = "word";
	
	// Select word to guess
	int selectedWordIndex = rand() % wordCount;
	printf("Selected Word: %s \n", words[selectedWordIndex]);
	
	printf("Test");

	return 0;
}
