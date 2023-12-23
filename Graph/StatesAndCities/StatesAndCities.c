#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "StatesAndCities.h"

typedef struct
{
    int from;
    int to;
    size_t length;
} Road;

typedef struct
{
    int* cities;
    size_t numberCities;
} State;

struct InputData
{
    int numberRoads;
    int numberStates;
    int numberCities;
    int* unassignedCities;
    Road* roads;
    State* states;
};

InputData* readDataFromFile(const char* const fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return NULL;
    }

    InputData* inputData = (InputData*)calloc(1, sizeof(InputData));
    if (inputData == NULL)
    {
        fclose(file);
        return NULL;
    }

    if (fscanf(file, "%d %d\n", &inputData->numberCities, &inputData->numberRoads) != 2)
    {
        fclose(file);
        free(inputData);
        return NULL;
    }

    inputData->unassignedCities = (int*)calloc(inputData->numberCities, sizeof(int));
    if (inputData->unassignedCities == NULL)
    {
        fclose(file);
        free(inputData);
        return NULL;
    }

    for (size_t i = 0; i < inputData->numberCities; ++i)
    {
        inputData->unassignedCities[i] = 1;
    }

    inputData->roads = (Road*)calloc(inputData->numberRoads, sizeof(Road));
    if (inputData->roads == NULL)
    {
        fclose(file);
        free(inputData->unassignedCities);
        free(inputData);
        return NULL;
    }

    for (int i = 0; i < inputData->numberRoads; ++i)
    {
        if (fscanf(file, "%d %d %zd\n", &inputData->roads[i].from, &inputData->roads[i].to, &inputData->roads[i].length) != 3)
        {
            fclose(file);
            free(inputData->unassignedCities);
            free(inputData->roads);
            free(inputData);
            return NULL;
        }
    }

    if (fscanf(file, "%d\n", &inputData->numberStates) != 1)
    {
        fclose(file);
        free(inputData->unassignedCities);
        free(inputData->roads);
        free(inputData);
        return NULL;
    }

    inputData->states = (State*)malloc(inputData->numberStates * sizeof(State));
    if (inputData->states == NULL)
    {
        fclose(file);
        free(inputData->unassignedCities);
        free(inputData->roads);
        free(inputData);
        return NULL;
    }

    int capital = 0;
    for (int i = 0; i < inputData->numberStates; ++i)
    {
        if (fscanf(file, "%d ", &capital) != 1)
        {
            fclose(file);
            free(inputData->unassignedCities);
            free(inputData->roads);
            free(inputData->states);
            free(inputData);
            return NULL;
        }

        inputData->states[i].cities = (int*)calloc(inputData->numberCities, sizeof(int));
        if (inputData->states[i].cities == NULL)
        {
            fclose(file);
            free(inputData->unassignedCities);
            free(inputData->roads);
            free(inputData->states);
            free(inputData);
            return NULL;
        }
        inputData->states[i].cities[0] = capital;
        inputData->states[i].numberCities = 1;
        inputData->unassignedCities[capital - 1] = 0;
    }

    fclose(file);
    return inputData;
}

static int findClosestCity(InputData* inputData, size_t index)
{
    int closestCity = 0;
    size_t minDistance = SIZE_MAX;
    int* sourceCities = inputData->states[index].cities;

    for (int i = 0; i < inputData->numberCities; ++i)
    {
        if (inputData->unassignedCities[i] != 1)
        {
            continue;
        }

        for (size_t j = 0; j < inputData->numberCities; ++j)
        {
            if (sourceCities[j] == 0)
            {
                continue;
            }

            int roadIndex = -1;
            for (int k = 0; k < inputData->numberRoads; ++k)
            {
                if ((inputData->roads[k].from == i + 1 && inputData->roads[k].to == sourceCities[j]) ||
                    (inputData->roads[k].to == i + 1 && inputData->roads[k].from == sourceCities[j]))
                {
                    roadIndex = k;
                    break;
                }
            }

            if (roadIndex != -1 && inputData->roads[roadIndex].length < minDistance)
            {
                minDistance = inputData->roads[roadIndex].length;
                closestCity = i + 1;
            }
        }
    }
    return closestCity;
}

void distributeCities(InputData* inputData)
{
    int countFreeCity = inputData->numberCities - inputData->numberStates;

    while (countFreeCity)
    {
        for (size_t i = 0; i < inputData->numberStates; i++)
        {
            int closest_city = findClosestCity(inputData, i);
            if (closest_city > 0)
            {
                inputData->unassignedCities[closest_city - 1] = 0;
                inputData->states[i].cities[inputData->states[i].numberCities++] = closest_city;
                --countFreeCity;
            }
        }
    }
}

void printResult(InputData* inputData)
{
    for (int i = 0; i < inputData->numberStates; i++)
    {
        printf("State %d: ", i + 1);
        for (size_t j = 0; j < inputData->states[i].numberCities; j++)
        {
            printf("%d ", inputData->states[i].cities[j]);
        }
        printf("\n");
    }
}

void deleteInputData(InputData** inputData)
{
    for (int i = 0; i < (*inputData)->numberStates; i++)
    {
        free((*inputData)->states[i].cities);
    }

    free((*inputData)->unassignedCities);
    free((*inputData)->roads);
    free((*inputData)->states);
    free(*inputData);
    *inputData = NULL;
}

int* convertToArray(const InputData* const inputData)
{
    size_t numberCities = inputData->numberCities;
    int* array = (int*)malloc(numberCities * sizeof(int));
    if (array == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < inputData->numberStates; ++i)
    {
        size_t sizeStates = inputData->states[i].numberCities;
        for (size_t j = 0; j < sizeStates; ++j)
        {
            array[i * sizeStates + j] = inputData->states[i].cities[j];
        }
    }

    return array;
}
