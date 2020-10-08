#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

bool inArray(const char *arr, const char c){
	for (int i = 0; i < sizeof(&arr)/sizeof(arr[0]); ++i){
		if(arr[i] == c) return true;
	}
	return false;
}

int countChar(const char *arr, const char c){
	int count = 0;
	for (int i = 0; i < sizeof(&arr)/sizeof(arr[0]); ++i){
		if(arr[i] == c) {
			count++;
		}
	}
	return count;
}

int main(){
	// Seed the random number generator with current time
	srand(time(0));	
	
	int lives = 10;
	char guess;
	char previousGuesses[26];
	int guessIndex = 0;
	int correctGuesses = 0;

	for (int i = 0; i < sizeof(previousGuesses)/sizeof(previousGuesses[0]); ++i){
		previousGuesses[i] = ' ';
	}

	// Declare words
	#define WORD_COUNT 34
	#define MAX_STRING_LENGTH 20
	const char words[WORD_COUNT][MAX_STRING_LENGTH] = 
	{"test",
	 "word",
	 "microphone",
	 "abruptly",
	 "azure",
	 "bandwagon",
	 "bayou",
	 "bikini",
	 "blizzard",
	 "caliph",
	 "equip",
	 "fixable",
	 "flapjack",
	 "glyph",
	 "haphazard",
	 "injury",
	 "jazz",
	 "khaki",
	 "kiwi",
	 "luxury",
	 "nymph",
	 "oxygen",
	 "pneumonia",
	 "quartz",
	 "lucky",
	 "matrix",
	 "microwave",
	 "psyche",
	 "rhythm",
	 "sphinx",
	 "topaz",
	 "witchcraft",
	 "whisky",
	 "voyeur"
	};	

	// Select word to guess
	int selectedWordIndex = rand() % WORD_COUNT;
	//printf("Selected Word: %s \n", words[selectedWordIndex]);
	int wordLength = 0;
	for (int i = 0; i < MAX_STRING_LENGTH; i++){
		if (isalpha(words[selectedWordIndex][i])){
			wordLength++;
		}
	}	

	
	// Main Logic Loop
	while (lives > 0){
		// There are extra getchars following each input, these prevent the newline from the user
		// from triggering the input again causing them to lose a life every time they guess
		printf("\n\nLives: %d \n\n", lives);
		
		printf("Previous Guesses: ");
		for(int index = 0; index < 26; ++index){
			if(isalpha(previousGuesses[index])){
				printf("%c ", previousGuesses[index]);
			}
		}
		printf("\nWord: ");
		for(int index = 0; index < wordLength; ++index){
			if(inArray(previousGuesses ,words[selectedWordIndex][index])){
				printf("%c", words[selectedWordIndex][index]);
			} else {
				printf("_");
			}
		}

		printf("\nEnter Guess: ");
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
			correctGuesses += countChar(words[selectedWordIndex], guess);
		} else {
			lives--;
		}
		if (correctGuesses == wordLength){
			printf("\n\n\n\nYou Won!\n\n\n\n");
			break;
		}
	}
	
	printf("\n\n\n\nYou Lost, out of lives!\n\n\n\n");

	return 0;
}
