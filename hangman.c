#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool inArray(char *arr, char *c){
	for (int i = 0; i < sizeof(&arr)/sizeof(arr[0]); ++i){
		if(arr[i] == c) return true;
	}
	return false;
}

int main(){
	// Seed the random number generator with current time
	srand(time(0));	
	
	int lives = 5;
	char guess;
	char previousGuesses[26];

	// Declare words
	int wordCount = 2;
	const char *words[wordCount];
	words[0] = "test";
	words[1] = "word";
	
	// Select word to guess
	int selectedWordIndex = rand() % wordCount;
	printf("Selected Word: %s \n", words[selectedWordIndex]);
	
	while (lives > 0){
		printf("Lives: %d \n", lives);
		printf("Enter Guess: ");
		scanf("%c", &guess);

		if (inArray(words[selectedWordIndex], guess)) {
			printf("Guess is in word \n");
		}
		lives--;
	}

	return 0;
}
