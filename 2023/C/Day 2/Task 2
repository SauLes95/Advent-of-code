#define _CRT_SECURE_NO_WARNINGS
#define RED 12
#define GREEN 13
#define BLUE 14

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void checkLine(char*, int*, int*, int*);

int main() {
	FILE* dataFile = fopen("day2.txt", "r");

	int fileLen = 100;
	int sumOfMaxBalls = 0;
    char unrefinedLine[1000];

	for (int i = 0; i < fileLen; i++) {
        int red = 0, blue = 0, green = 0;
        int counter = 0;
		int currentGame;

		fscanf(dataFile, "Game %d: %[^\n]%*c", &currentGame, unrefinedLine);

        char* token;
        char* refinedLine = unrefinedLine;

        while ((token = strtok_s(refinedLine, ";", &refinedLine)) != NULL) {
            char tmpRefinedLine[1000];
            strcpy(tmpRefinedLine, token);

            checkLine(tmpRefinedLine, &red, &green, &blue);
        }
         
        sumOfMaxBalls += (red * green * blue);

	}

    printf("Summary of correct games is: %d", sumOfMaxBalls);
	fclose(dataFile);
	return 0;
}

void checkLine(char* line, int* red, int* blue, int* green) {
    char tmpLine[1000];
    strcpy(tmpLine, line);

    char* token = strtok(tmpLine, ",");

    while (token != NULL) {
        int numOfBalls = 0;
        char colour[100];

        if (sscanf(token, " %d %s", &numOfBalls, colour) == 2) {

            if (strcmp(colour, "red") == 0 && numOfBalls > *red) {
                *red = numOfBalls;
            }
            else if (strcmp(colour, "green" ) == 0 && numOfBalls > *green) {
                *green = numOfBalls;
            }
            else if (strcmp(colour, "blue") == 0 && numOfBalls > *blue) {
                *blue = numOfBalls;
            }
        }

        token = strtok(NULL, ",");
    }

}
