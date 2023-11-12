#include "BalanceBrackets.h"
#include "Stack.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ERROR_STR "Error!\n"

bool isBracketsCorrect(const char* const string)
{
    ErrorCode errorCode = ok;
    Stack* brackets = NULL;
    char open[] = "{([";
    char close[] = "})]";
    for (const char* character = string; *character != '\0'; ++character) 
    {
        if (strchr(open, *character) != NULL) 
        {
            if (push(&brackets, *character) != ok)
            {
                free(brackets);
                printf(ERROR_STR);
                return false;
            }
        }
        else if (strchr(close, *character) != NULL)
        {
            char element = top(brackets, &errorCode);
            if (errorCode != ok)
            {
                free(brackets);
                return false;
            }
            pop(&brackets);

            if ((strchr(close, *character) - close) != (strchr(open, element) - open))
                return false;
        }
    }
    return true;
}
