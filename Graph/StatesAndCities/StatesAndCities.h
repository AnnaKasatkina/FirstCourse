#pragma once

typedef struct InputData InputData;

InputData* readDataFromFile(const char* const fileName);

void distributeCities(InputData* inputData);

void printResult(InputData* inputData);

void deleteInputData(InputData** inputData);

int* convertToArray(const InputData* const inputData);
