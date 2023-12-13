#define _CRT_SECURE_NO_WARNINGS
#define MAX_WINNING_NUMBERS 10
#define MAX_NUMBERS_YOU_HAVE 25
#define NUMBER_OF_GAMES 193

#include <stdio.h>
#include <math.h>

int main() {

    FILE* file = fopen("day4.txt", "r");
    int winningNumbers[MAX_WINNING_NUMBERS];
    int numbersYouHave[MAX_NUMBERS_YOU_HAVE];
    int numbersOfCopies[NUMBER_OF_GAMES];
    for (int i = 0; i < NUMBER_OF_GAMES; i++) {
        numbersOfCopies[i] = 1;
    }

    int gameNumber;
    int numberOfScratchcards = 0;

    for (int i = 0; i < NUMBER_OF_GAMES; i++) {

        fscanf(file, "Card %d : %d %d %d %d %d %d %d %d %d %d | %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &gameNumber, &winningNumbers[0], &winningNumbers[1], &winningNumbers[2], &winningNumbers[3], &winningNumbers[4], &winningNumbers[5], &winningNumbers[6], &winningNumbers[7], &winningNumbers[8], &winningNumbers[9], &numbersYouHave[0], &numbersYouHave[1], &numbersYouHave[2], &numbersYouHave[3], &numbersYouHave[4], &numbersYouHave[5], &numbersYouHave[6], &numbersYouHave[7], &numbersYouHave[8], &numbersYouHave[9], &numbersYouHave[10], &numbersYouHave[11], &numbersYouHave[12], &numbersYouHave[13], &numbersYouHave[14], &numbersYouHave[15], &numbersYouHave[16], &numbersYouHave[17], &numbersYouHave[18], &numbersYouHave[19], &numbersYouHave[20], &numbersYouHave[21], &numbersYouHave[22], &numbersYouHave[23], &numbersYouHave[24]);
        

        for (int j = 0; j < numbersOfCopies[i]; j++) {
            int tmpGameNumber = gameNumber;

            for (int k = 0; k < MAX_WINNING_NUMBERS; k++) {
                for (int l = 0; l < MAX_NUMBERS_YOU_HAVE; l++) {


                    if (winningNumbers[k] == numbersYouHave[l]) {

                        if (tmpGameNumber < NUMBER_OF_GAMES) {
                            numbersOfCopies[tmpGameNumber] += 1;
                            tmpGameNumber++;
                        }    
                    }
                
                }
            }
        }
    }

    for (int i = 0; i < NUMBER_OF_GAMES; i++) {
        numberOfScratchcards += numbersOfCopies[i];
    }

    printf("Number of scratchcards is %d\n", numberOfScratchcards);
    fclose(file);
    return 0;
}
