#define _CRT_SECURE_NO_WARNINGS
#define MAX_WINNING_NUMBERS 10
#define MAX_NUMBERS_YOU_HAVE 25

#include <stdio.h>
#include <math.h>

int main() {

	FILE* file = fopen("day4.txt", "r");
	int numOfLines = 193;
	int winningNumbers[MAX_WINNING_NUMBERS];
	int numbersYouHave[MAX_NUMBERS_YOU_HAVE];
	int gameNumber;
	int totalPoints = 0;


	for (int i = 0; i < numOfLines; i++) {
		int gamePoints = -1;

		fscanf(file, "Card %d : %d %d %d %d %d %d %d %d %d %d | %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &gameNumber, &winningNumbers[0], &winningNumbers[1], &winningNumbers[2], &winningNumbers[3], &winningNumbers[4], &winningNumbers[5], &winningNumbers[6], &winningNumbers[7], &winningNumbers[8], &winningNumbers[9], &numbersYouHave[0], &numbersYouHave[1], &numbersYouHave[2], &numbersYouHave[3], &numbersYouHave[4], &numbersYouHave[5], &numbersYouHave[6], &numbersYouHave[7], &numbersYouHave[8], &numbersYouHave[9], &numbersYouHave[10], &numbersYouHave[11], &numbersYouHave[12], &numbersYouHave[13], &numbersYouHave[14], &numbersYouHave[15], &numbersYouHave[16], &numbersYouHave[17], &numbersYouHave[18], &numbersYouHave[19], &numbersYouHave[20], &numbersYouHave[21], &numbersYouHave[22], &numbersYouHave[23], &numbersYouHave[24]);
		
		for (int i = 0; i < MAX_WINNING_NUMBERS; i++) {
			for (int j = 0; j < MAX_NUMBERS_YOU_HAVE; j++) {
				if (winningNumbers[i] == numbersYouHave[j]) {
					gamePoints++;
				}
			}
		}

		if (gamePoints == -1) {
			totalPoints += 0;
		}
		else
		{
			totalPoints += pow(2, gamePoints);
		}
	}

	printf("Number of points is %d\n", totalPoints);

	fclose(file);
	return 0;
}
