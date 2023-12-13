#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include<stdlib.h>

typedef struct
{
	unsigned long long destinatioRangeStart;
	unsigned long long sourceRangeStart;
	unsigned long long rangeLength;
}FileStruct;


unsigned long long* enterSeedsFromFile(const int);
FileStruct* enterSeedsToSoilFromFile(const int);
FileStruct* enterSoilToFertilizerFromFile(const int);
FileStruct* enterFertilizerToWaterFromFile(const int);
FileStruct* enterWaterToLightFromFile(const int);
FileStruct* enterLightToTemperatureFromFile(const int);
FileStruct* enterTemperatureToHumidityFromFile(const int);
FileStruct* enteHumidityToLocationFromFile(const int);
unsigned long long convertHumidityToLocation(unsigned long long, FileStruct*, const int);
unsigned long long convertToHigher(unsigned long long, FileStruct*, const int);
unsigned long long convertSeedsToSoil(unsigned long long, FileStruct*, const int);
unsigned long long convertSoilToFertilizer(unsigned long long, FileStruct*, const int);
unsigned long long convertFertilizerToWater(unsigned long long, FileStruct*, const int);
unsigned long long convertWaterToLight(unsigned long long, FileStruct*, const int);
unsigned long long convertLightToTemperature(unsigned long long, FileStruct*, const int);
unsigned long long convertTemperatureToHumidity(unsigned long long, FileStruct*, const int);

void bubbleSort(unsigned long long*, int);
void bubbleSortFileStruct(FileStruct*, int);
void dealocateOneDArray(unsigned long long*);
void dealocateFileStructs(FileStruct*);


int main() {

	const int seedsFileSize = 20;
	unsigned long long* seeds = enterSeedsFromFile(seedsFileSize);
	bubbleSort(seeds,seedsFileSize);

	const int seedsToSoilFileSize = 16;
	FileStruct* seedsToSoil = enterSeedsToSoilFromFile(seedsToSoilFileSize);
	bubbleSortFileStruct(seedsToSoil, seedsToSoilFileSize);

	const int soilToFertilizerFileSize = 33;
	FileStruct* soilToFertilizer = enterSoilToFertilizerFromFile(soilToFertilizerFileSize);
	bubbleSortFileStruct(soilToFertilizer, seedsToSoilFileSize);

	const int fertilizerToWaterFileSize = 26;
	FileStruct* fertilizerToWater = enterFertilizerToWaterFromFile(fertilizerToWaterFileSize);
	bubbleSortFileStruct(fertilizerToWater, fertilizerToWaterFileSize);

	const int waterToLightFileSize = 38;
	FileStruct* waterToLight = enterWaterToLightFromFile(waterToLightFileSize);
	bubbleSortFileStruct(waterToLight, waterToLightFileSize);

	const int lightToTemperatureFileSize = 10;
	FileStruct* lightToTemperature = enterLightToTemperatureFromFile(lightToTemperatureFileSize);
	bubbleSortFileStruct(lightToTemperature, lightToTemperatureFileSize);

	const int temperatureToHumidityFileSize = 37;
	FileStruct* temperatureToHumidity = enterTemperatureToHumidityFromFile(temperatureToHumidityFileSize);
	bubbleSortFileStruct(temperatureToHumidity, temperatureToHumidityFileSize);

	const int humidityToLocationFileSize = 22;
	FileStruct* humidityToLocation = enteHumidityToLocationFromFile(humidityToLocationFileSize);
	bubbleSortFileStruct(humidityToLocation, humidityToLocationFileSize);

	unsigned long long theSmallestLocation = humidityToLocation[humidityToLocationFileSize -1].destinatioRangeStart + humidityToLocation[humidityToLocationFileSize - 1].rangeLength;

	for (int i = 0; i < seedsFileSize; i++) {
		unsigned long long soil = convertSeedsToSoil(seeds[i], seedsToSoil, seedsToSoilFileSize);
		unsigned long long fertilizer = convertSoilToFertilizer(soil, soilToFertilizer, soilToFertilizerFileSize);
		unsigned long long water = convertFertilizerToWater(fertilizer, fertilizerToWater, fertilizerToWaterFileSize);
		unsigned long long light = convertWaterToLight(water, waterToLight, waterToLightFileSize);
		unsigned long long temperature = convertLightToTemperature(light, lightToTemperature, lightToTemperatureFileSize);
		unsigned long long humidity = convertTemperatureToHumidity(temperature, temperatureToHumidity, temperatureToHumidityFileSize);
		unsigned long long location = convertHumidityToLocation(humidity, humidityToLocation, humidityToLocationFileSize);

		if (location < theSmallestLocation) {
			theSmallestLocation = location;
		}
	}
	
	printf("The smallest location is %llu", theSmallestLocation);

	dealocateOneDArray(seeds);
	dealocateFileStructs(seedsToSoil);
	dealocateFileStructs(soilToFertilizer);
	dealocateFileStructs(fertilizerToWater);
	dealocateFileStructs(waterToLight);
	dealocateFileStructs(lightToTemperature);
	dealocateFileStructs(temperatureToHumidity);
	dealocateFileStructs(humidityToLocation);

	return 0;
}


unsigned long long* enterSeedsFromFile(const int seedsFileSize) {
	FILE* seedsFile = fopen("day4seeds.txt", "r");
	unsigned long long* seeds = (unsigned long long*)malloc(seedsFileSize * sizeof(unsigned long long));

	for (int i = 0; i < seedsFileSize; i++) {
		fscanf(seedsFile, "%llu", &seeds[i]);
	}

	fclose(seedsFile);
	return seeds;
}

FileStruct* enterSeedsToSoilFromFile(const int seedsToSoilFileSize) {
	FILE* seedToSoilFile = fopen("day4seeds2soil.txt", "r");
	FileStruct* seedsToSoil = (FileStruct*)malloc(seedsToSoilFileSize * sizeof(FileStruct));

	for (int i = 0; i < seedsToSoilFileSize; i++) {
		fscanf(seedToSoilFile, "%llu %llu %llu", &seedsToSoil[i].destinatioRangeStart, &seedsToSoil[i].sourceRangeStart, &seedsToSoil[i].rangeLength);;
	}

	fclose(seedToSoilFile);
	return seedsToSoil;
}

FileStruct* enterSoilToFertilizerFromFile(const int soilToFertilizerFileSize) {
	FILE* soilToFertilizerFile = fopen("day4soil2fertilizer.txt", "r");
	FileStruct* soilToFertilizer = (FileStruct*)malloc(soilToFertilizerFileSize * sizeof(FileStruct));

	for (int i = 0; i < soilToFertilizerFileSize; i++) {
		fscanf(soilToFertilizerFile, "%llu %llu %llu", &soilToFertilizer[i].destinatioRangeStart, &soilToFertilizer[i].sourceRangeStart, &soilToFertilizer[i].rangeLength);;
	}

	fclose(soilToFertilizerFile);
	return soilToFertilizer;
}

FileStruct* enterFertilizerToWaterFromFile(const int fertilizerToWaterFileSize) {
	FILE* fertilizerToWaterFile = fopen("day4fertilizer2water.txt", "r");
	FileStruct* fertilizerToWater = (FileStruct*)malloc(fertilizerToWaterFileSize * sizeof(FileStruct));

	for (int i = 0; i < fertilizerToWaterFileSize; i++) {
		fscanf(fertilizerToWaterFile, "%llu %llu %llu", &fertilizerToWater[i].destinatioRangeStart, &fertilizerToWater[i].sourceRangeStart, &fertilizerToWater[i].rangeLength);;
	}

	fclose(fertilizerToWaterFile);
	return fertilizerToWater;
}

FileStruct* enterWaterToLightFromFile(const int waterToLightFileSize) {
	FILE* waterToLightFile = fopen("day4water2light.txt", "r");
	FileStruct* waterToLight = (FileStruct*)malloc(waterToLightFileSize * sizeof(FileStruct));

	for (int i = 0; i < waterToLightFileSize; i++) {
		fscanf(waterToLightFile, "%llu %llu %llu", &waterToLight[i].destinatioRangeStart, &waterToLight[i].sourceRangeStart, &waterToLight[i].rangeLength);;
	}

	fclose(waterToLightFile);
	return waterToLight;
}

FileStruct* enterLightToTemperatureFromFile(const int lightToTemperatureFileSize) {
	FILE* lightToTemperatureFile = fopen("day4light2temperature.txt", "r");
	FileStruct* lightToTemperature = (FileStruct*)malloc(lightToTemperatureFileSize * sizeof(FileStruct));

	for (int i = 0; i < lightToTemperatureFileSize; i++) {
		fscanf(lightToTemperatureFile, "%llu %llu %llu", &lightToTemperature[i].destinatioRangeStart, &lightToTemperature[i].sourceRangeStart, &lightToTemperature[i].rangeLength);;
	}

	fclose(lightToTemperatureFile);
	return lightToTemperature;
}

FileStruct* enterTemperatureToHumidityFromFile(const int temperatureToHumidityFileSize) {
	FILE* temperatureToHumidityFile = fopen("day4temperature2humidity.txt", "r");
	FileStruct* temperatureToHumidity = (FileStruct*)malloc(temperatureToHumidityFileSize * sizeof(FileStruct));

	for (int i = 0; i < temperatureToHumidityFileSize; i++) {
		fscanf(temperatureToHumidityFile, "%llu %llu %llu", &temperatureToHumidity[i].destinatioRangeStart, &temperatureToHumidity[i].sourceRangeStart, &temperatureToHumidity[i].rangeLength);;
	}

	fclose(temperatureToHumidityFile);
	return temperatureToHumidity;
}

FileStruct* enteHumidityToLocationFromFile(const int humidityToLocationFileSize) {
	FILE* humidityToLocationFile = fopen("day4humidity2location.txt", "r");
	FileStruct* humidityToLocation = (FileStruct*)malloc(humidityToLocationFileSize * sizeof(FileStruct));

	for (int i = 0; i < humidityToLocationFileSize; i++) {
		fscanf(humidityToLocationFile, "%llu %llu %llu", &humidityToLocation[i].destinatioRangeStart, &humidityToLocation[i].sourceRangeStart, &humidityToLocation[i].rangeLength);;
	}

	fclose(humidityToLocationFile);
	return humidityToLocation;
}


unsigned long long convertToHigher(unsigned long long lower, FileStruct* lowerToHigherFile, const int lowerToHigherFileSize) {
	for (int i = 0; i < lowerToHigherFileSize; i++) {
		if (lower >= lowerToHigherFile[i].sourceRangeStart && lower <= (lowerToHigherFile[i].sourceRangeStart + lowerToHigherFile[i].rangeLength)) {
			return lowerToHigherFile[i].destinatioRangeStart + lower - lowerToHigherFile[i].sourceRangeStart;
		}
	}

	return lower;
}

unsigned long long convertSeedsToSoil(unsigned long long seed, FileStruct* seedsToSoil, const int seedsToSoilFileSize) {
	
	return convertToHigher(seed, seedsToSoil, seedsToSoilFileSize);
}

unsigned long long convertSoilToFertilizer(unsigned long long soil, FileStruct* soilToFertilizer, const int soilToFertilizerFileSize) {

	return convertToHigher(soil, soilToFertilizer, soilToFertilizerFileSize);
}

unsigned long long convertFertilizerToWater(unsigned long long fertilizer, FileStruct* fertilizerToWater, const int fertilizerToWaterFileSize) {

	return convertToHigher(fertilizer, fertilizerToWater, fertilizerToWaterFileSize);
}

unsigned long long convertWaterToLight(unsigned long long water, FileStruct* waterToLight, const int waterToLightFileSize) {

	return convertToHigher(water, waterToLight, waterToLightFileSize);
}

unsigned long long convertLightToTemperature(unsigned long long light, FileStruct* lightToTemperature, const int lightToTemperatureFileSize) {

	return convertToHigher(light, lightToTemperature, lightToTemperatureFileSize);
}

unsigned long long convertTemperatureToHumidity(unsigned long long temperature, FileStruct* temperatureToHumidity, const int temperatureToHumidityFileSize) {

	return convertToHigher(temperature, temperatureToHumidity, temperatureToHumidityFileSize);
}

unsigned long long convertHumidityToLocation(unsigned long long humidity, FileStruct* humidityToLocation, const int humidityToLocationFileSize) {

	return convertToHigher(humidity, humidityToLocation, humidityToLocationFileSize);
}


void bubbleSort(unsigned long long* array, int fileSize) {
	int wasSwitch = 1;

	while (wasSwitch) {
		wasSwitch = 0;
		for (int i = 0; i < fileSize - 1; i++) {
			if (array[i] > array[i + 1]) {
				unsigned long tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;

				wasSwitch = 1;
			}
		}
	}
}

void bubbleSortFileStruct(FileStruct* tmpStruct, int fileSize) {
	int wasSwitch = 1;

	while (wasSwitch) {
		wasSwitch = 0;
		for (int i = 0; i < fileSize - 1; i++) {
			if (tmpStruct[i].destinatioRangeStart > tmpStruct[i + 1].destinatioRangeStart) {
				FileStruct tmp = tmpStruct[i];
				tmpStruct[i] = tmpStruct[i + 1];
				tmpStruct[i + 1] = tmp;

				wasSwitch = 1;
			}
		}
	}
}


void dealocateOneDArray(unsigned long long* array) {
	free(array);
}

void dealocateFileStructs(FileStruct* tmpStruct) {
	free(tmpStruct);
}
