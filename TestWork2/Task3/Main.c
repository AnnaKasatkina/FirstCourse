#include <stdio.h>

#include "Task3.h"
#include "Tests.h"

#define ERROR -1

int main(void) 
{
    if (!testResult())
    {
        printf("Error!");
        return ERROR;
    }
    char* testString = "Abc123_xyz";

    printf(processString(testString) ? "Ok\n" : "Error\n");
    return 0;
}
