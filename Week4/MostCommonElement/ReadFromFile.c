#include "ReadFromFile.h"

#include <stdio.h>

int* openFile(size_t* const length, const char * const nameFile)
{
    FILE* file = fopen(nameFile, "r");
    if (file == NULL)
    {
        return NULL;
    }

    fscanf(file, "%d ", length);

    int* array = (int*)malloc(sizeof(int) * (*length));
    for (size_t i = 0; i < (*length); ++i)
    {
        if (fscanf(file, "%d ", &array[i]) != 1)
        {
            free(array);
            return NULL;
        }
    }

    fclose(file);
    return array;
}
