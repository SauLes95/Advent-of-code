#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {

	FILE* dataFile = fopen("day1.txt", "r");
	
	int numOfLines = 1000;
	char line[100];
	int sum = 0;

	for (int i = 0; i < numOfLines; i++) {
		fscanf(dataFile,"%s", & line);
		
		int tmpBegin;
		int tmpEnd;

		for (int j = 0; j < strlen(line); j++) {
			if (line[j] >= '0' && line[j] <= '9') {
				tmpBegin = line[j] - 48;
				break;
			}
			else {
				tmpBegin = 0;
			}
		}

		for (int j = strlen(line) - 1; j >= 0; j--) {
			if (line[j] >= '0' && line[j] <= '9') {
				tmpEnd = line[j] - 48;
				break;
			}
			else {
				tmpEnd = 0;
			}
		}

		sum += tmpBegin * 10 + tmpEnd;
	}

	printf("Sum of all numbers is \t%d", sum);

	fclose(dataFile);
	return 0;
}
