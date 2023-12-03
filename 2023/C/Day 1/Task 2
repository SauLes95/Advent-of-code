#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char* numbers[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int findFirst(char*);
char* strrstr(char*, char*);
int findLast(char*);

int main() {

	FILE* dataFile = fopen("day1.txt", "r");
	
	int numOfLines = 1000;
	char line[100];
	int sum = 0;

	for (int i = 0; i < numOfLines; i++) {
		fscanf(dataFile,"%s", & line);
		int first = findFirst(line);
		int last = findLast(line);
		sum += first + last;
	}

	printf("Sum of all numbers is \t%d", sum);

	fclose(dataFile);
	return 0;
}


int findFirst(char* line) {

	

	if (line[0] >= '0' && line[0] <= '9') {
		return (line[0] - 48) * 10;
	}

	char* numberStrings[10] = { 0 };
	char* firstNumberString = 0;
	int first = -1;

	
	for (int i = 1; i < strlen(line); i++) {

		if (line[i] >= '0' && line[i] <= '9') {
			firstNumberString = &line[i];
			first = (line[i] - 48) * 10;
			break;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (strstr(line, numbers[i]) != NULL) {
			numberStrings[i] = strstr(line, numbers[i]);
		}
	}
	

	for (int i = 0; i < 10; i++) {

		if (numberStrings[i] != NULL) {
			if (strlen(numberStrings[i]) > strlen(firstNumberString)) {
				firstNumberString = numberStrings[i];
				first = i * 10;
			}
		}

	}

	return first;
}

char* strrstr(const char* haystack, const char* needle) {

	char* last = NULL;
	char* found;


	if (strstr(haystack, needle) == NULL) {
		return NULL;
	}
	else{
		while ((found = strstr(haystack, needle)) != NULL) {
			last = found;
			haystack = found + 1;
		}
	}

	return last;
}

int findLast(char* line) {

	char* numberStrings[10] = { 0 };
	char* lastNumberString = 0;
	int last = -1;

	for (int i = 0; i < strlen(line); i++) {

		if (line[i] >= '0' && line[i] <= '9') {
			lastNumberString = &line[i];
			last = line[i] - 48;
			if (i == strlen(line) - 1) {
				return last;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		if (strstr(line, numbers[i]) != NULL) {
			numberStrings[i] = strrstr(line, numbers[i]);
		}
	}


	for (int i = 0; i < 10; i++) {
		
		if (numberStrings[i] != NULL) {
			if (strlen(numberStrings[i]) < strlen(lastNumberString)) {
				lastNumberString = numberStrings[i];
				last = i;
			}
		}
		
	}

	return last;
}
