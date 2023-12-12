#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

bool checkForSign(char);
int extractNumber(char**, int, int);
int turnIntoOneDigitNumber(char);
int turnIntoTwoDigitNumber(char, char);
int turnIntoThreeDigitNumber(char, char, char);

int main() {

	FILE* file = fopen("day3.txt", "r");
	int numberOfLines = 140;
	int sum = 0;

	char** array = (char**)malloc(numberOfLines * sizeof(char*));

	for (int i = 0; i < numberOfLines; i++) {
		char tmpLine[1000];

		fscanf(file, "%s", tmpLine);
		array[i] = (char*)malloc(strlen(tmpLine) * sizeof(char) + 1);
		strcpy(array[i], tmpLine);
	}



	for (int i = 1; i < numberOfLines - 1; i++) {
		for (int j = 3; j < strlen(array[i]) - 3; j++) {
			if (checkForSign(array[i][j])) {
				sum += extractNumber(array, i, j);
			}
		}
	}


	for (int i = 0; i < numberOfLines; i++) {
		free(array[i]);
	}
	free(array);
	fclose(file);

	printf("Sum of all numbers is %d", sum);
	return 0;
}

bool checkForSign(char sign) {
	if (sign != '.' && !(sign >= '0' && sign <= '9')) {
		return true;
	}
	return false;
}


int extractNumber(char** array, int rowIdx, int colIdx) {
	int sum = 0;

	for (int i = rowIdx - 1; i < rowIdx + 2; i++) {
		for (int j = colIdx - 3 ; j < colIdx + 2; j++) {
			int tmpSum = 0;
			if (j == colIdx - 3) {
				if (array[i][j] >= '0' && array[i][j] <= '9' && array[i][j + 1] >= '0' && array[i][j + 1] <= '9' && array[i][j + 2] >= '0' && array[i][j + 2] <= '9') {
					sum += turnIntoThreeDigitNumber(array[i][j], array[i][j + 1], array[i][j + 2]);
					j += 2;
				}
			}
			else if (j == colIdx - 2) {
				if (array[i][j] >= '0' && array[i][j] <= '9' && array[i][j + 1] >= '0' && array[i][j + 1] <= '9' && !(array[i][j + 2] >= '0' && array[i][j + 2] <= '9')) {
					sum += turnIntoTwoDigitNumber(array[i][j], array[i][j + 1]);
					j ++;
				}
				else if (array[i][j] >= '0' && array[i][j] <= '9' && array[i][j + 1] >= '0' && array[i][j + 1] <= '9' && array[i][j + 2] >= '0' && array[i][j + 2] <= '9') {
					sum += turnIntoThreeDigitNumber(array[i][j], array[i][j + 1], array[i][j + 2]);
					j += 2;
				}
			}
			else {
				if (array[i][j] >= '0' && array[i][j] <= '9' && !(array[i][j + 1] >= '0' && array[i][j + 1] <= '9')) {
					sum += turnIntoOneDigitNumber(array[i][j]);
				}
				else if (array[i][j] >= '0' && array[i][j] <= '9' && array[i][j + 1] >= '0' && array[i][j + 1] <= '9' && !(array[i][j + 2] >= '0' && array[i][j + 2] <= '9')) {
					sum += turnIntoTwoDigitNumber(array[i][j], array[i][j + 1]);
					j ++;
				}
				else if (array[i][j] >= '0' && array[i][j] <= '9' && array[i][j + 1] >= '0' && array[i][j + 1] <= '9' && array[i][j + 2] >= '0' && array[i][j + 2] <= '9') {
					sum += turnIntoThreeDigitNumber(array[i][j], array[i][j + 1], array[i][j + 2]);
					j += 2;
				}
			}
			
		}
	}

	return sum;
}

int turnIntoOneDigitNumber(char oner) {
	return oner - '0';
}

int turnIntoTwoDigitNumber(char tenner, char oner) {
	return ((tenner - '0') * 10 + oner - '0');
}

int turnIntoThreeDigitNumber(char hundred, char tenner, char oner) {
	return ((hundred - '0') * 100 + (tenner - '0') * 10 + oner - '0');
}
