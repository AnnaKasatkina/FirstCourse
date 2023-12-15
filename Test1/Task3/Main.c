#include <stdio.h>

#include "Task3.h"
#include "Tests.h"

#define NAME_FILE "Text.txt"
#define ERROR -1
#define ERROR_STRING "Error!"

int main(void)
{
    if (!testResult())
    {
        printf(ERROR_STRING);
        return ERROR;
    }
    char* string = getStringFromFile(NAME_FILE);
    if (string == NULL)
    {
        printf(ERROR_STRING);
        return ERROR;
    }
    printf(string);

    return 0;
}
