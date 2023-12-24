#pragma once

typedef struct InputData InputData;

InputData* readDataFromFile(const char* const fileName);

void distributeCities(InputData* const inputData);

void printResult(const InputData* const inputData);

void deleteInputData(InputData** const inputData);

int* convertToArray(const InputData* const inputData);
