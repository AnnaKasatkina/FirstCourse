#include "Stack.h"
#include "ShuntingYard.h"

#include <stdio.h>
#include <ctype.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1

int main(void)
{
    printf("Enter the expretion: ");
    ErrorCode errorCode = ok;
    char* string = (char*)malloc(sizeof(char));
    int length = getString(&errorCode, &string);
    if (errorCode == outOfMemory)
    {
        printf("Out of memory");
        return ERROR;
    }

    char* output = (char*)malloc((length + 1) * sizeof(char));
    size_t index = 0;

    Stack* operations = NULL;

    char* upper = "*/";
    char* lower = "+-";

    for (char* character = string; *character != '\0'; ++character)
    {
        if (isdigit(*character))
        {
            output[index] = *character;
            ++index;
        }
        else if (strchr(lower, *character))
        {
            while (operations != NULL && (strchr(lower, (char)top(operations, &errorCode)) || strchr(upper, (char)top(operations, &errorCode))))
            {
                output[index] = (char)top(operations, &errorCode);
                pop(&operations);
                ++index;
            }

            if (push(&operations, *character) != ok)
            {
                printf("Out of memory");
                return ERROR;
            }
        }
        else if (strchr(upper, *character))
        {
            while (operations != NULL && strchr(upper, (char)top(operations, &errorCode)))
            {
                output[index] = (char)top(operations, &errorCode);
                pop(&operations);
                ++index;
            }

            if (push(&operations, *character) != ok)
            {
                printf("Out of memory");
                return ERROR;
            }
        }
        else if (*character == '(')
        {
            if (push(&operations, *character) != ok)
            {
                printf("Out of memory");
                return ERROR;
            }
        }
        else if (*character == ')')
        {
            while (operations != NULL && (char)top(operations, &errorCode) != '(')
            {
                output[index] = (char)top(operations, &errorCode);
                pop(&operations);
                ++index;
            }
            pop(&operations);
        }
    }

    while (operations != NULL)
    {
        output[index] = (char)top(operations, &errorCode);
        pop(&operations);
        ++index;
    }

    output[index] = '\0';
    printf("Answer: % s\n", output);

    return 0;
}
