#include <stdio.h>

#include "StatesAndCities.h"
#include "Tests.h"

#define NAME_FILE "input.txt"
#define ERROR -1

int main(void)
{
    if (!testResult())
    {
        printf("Tests error!");
        return ERROR;
    }
    InputData* inputData = readDataFromFile(NAME_FILE);
    if (inputData == NULL)
    {
        printf("Error reading input data!\n");
        return 1;
    }

    distributeCities(inputData);
    printResult(inputData);
    deleteInputData(&inputData);
    return 0;
}
