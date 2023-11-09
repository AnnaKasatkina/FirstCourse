#include "MostCommonElement.h"

#include <stdio.h>

int isTheMostCommon(const int* const array, const size_t length)
{
    size_t count = 1;
    size_t maxCount = 0;
    int answer = array[0];
    for (size_t i = 1; i < length; ++i)
    {
        if (array[i] == array[i - 1])
        {
            ++count;
        }
        if (count >= maxCount)
        {
            answer = array[i];
            maxCount = count;
            count = 1;
        }
        count = 1;

    }
    return answer;
}

int* openFile(size_t* const length, bool* const error)
{
    FILE* file = fopen("Array.txt", "r");
    if (file == NULL)
    {
        int errorArray[] = { 404 };
        *error = true;
        return errorArray;
    }

    int value = 0;
    while (!feof(file))
    {
        if (fscanf(file, "%d ", &value) > 0)
        {
            ++(*length);
        }
    }
    int* array = (int*)calloc((*length), sizeof(int));

    fseek(file, 0, SEEK_SET);
    for (size_t i = 0; i < (*length); ++i)
    {
        if (fscanf(file, "%d ", &array[i]) != 1)
        {
            printf("Error!");
            *error = true;
            return array;
        }
    }

    fclose(file);
    return array;
}
