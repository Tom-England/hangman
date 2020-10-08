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
	int guessIndex = 0;
	int correctGuesses = 0;

	// Declare words
	int wordCount = 2;
	const char *words[wordCount];
	words[0] = "test";
	words[1] = "word";
	
	// Select word to guess
	int selectedWordIndex = rand() % wordCount;
	printf("Selected Word: %s \n", words[selectedWordIndex]);
	
	
	// Main Logic Loop
	while (lives > 0){
		// There are extra getchars following each input, these prevent the newline from the user
		// from triggering the input again causing them to lose a life every time they guess
		printf("\n\nLives: %d \n\n", lives);
		printf("Enter Guess: ");
		guess = getchar();
		getchar();
		while (inArray(previousGuesses, guess)){
			printf("\nGuess Again: ");
			guess = getchar();	
			getchar();
		}
		previousGuesses[guessIndex] = guess;
		guessIndex++;

		if (inArray(words[selectedWordIndex], guess)) {
			printf("Guess is in word \n");
			correctGuesses++;
		} else {
			lives--;
		}
		if (correctGuesses == sizeof(words[selectedWordIndex])/sizeof(char)){
			printf("\n\n\n\nYou Won!\n\n\n\n");
			break;
		}
	}

	return 0;
}
