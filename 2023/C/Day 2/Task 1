#define _CRT_SECURE_NO_WARNINGS
#define RED 12
#define GREEN 13
#define BLUE 14

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool checkLine(char*);

int main() {
	FILE* dataFile = fopen("day2.txt", "r");

	int fileLen = 100;
	int gameSum = 0;
    char unrefinedLine[1000];

	for (int i = 0; i < fileLen; i++) {
        int counter = 0;
		int currentGame;

		fscanf(dataFile, "Game %d: %[^\n]%*c", &currentGame, unrefinedLine);

        char* token;
        char* refinedLine = unrefinedLine;

        while ((token = strtok_s(refinedLine, ";", &refinedLine)) != NULL) {
            char tmpRefinedLine[1000];
            strcpy(tmpRefinedLine, token);

            if (!checkLine(tmpRefinedLine)) {
                counter++;
            }

        }

        if (counter == 0) {
            gameSum += currentGame;
        }
		

	}

    printf("Summary of correct games is: %d", gameSum);
	fclose(dataFile);
	return 0;
}

bool checkLine(char* line) {
    char tmpLine[1000];
    strcpy(tmpLine, line);

    char* token = strtok(tmpLine, ",");

    while (token != NULL) {
        int numOfBalls = 0;
        char colour[100];

        if (sscanf(token, " %d %s", &numOfBalls, colour) == 2) {
            if (strcmp(colour, "red") == 0 && numOfBalls > RED) {
                return false;
            }
            else if (strcmp(colour, "green") == 0 && numOfBalls > GREEN) {
                return false;
            }
            else if (strcmp(colour, "blue") == 0 && numOfBalls > BLUE) {
                return false;
            }
        }

        token = strtok(NULL, ",");
    }

    return true;
}
