#include "Stack.h"
#include "PostfixCalculator.h"
#include "Utility.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define ERROR -1
#define STACK_ERROR(X)\
    if ((X) != ok)\
    {\
        free(digits);\
        *errorCode = error;\
        return ERROR;\
    }


int postfixCalculator(char* const string, ErrorCode* const errorCode)
{
    Stack* digits = NULL;

    for (char* character = string; *character != '\0'; ++character)
    {
        if (*character == ' ')
        {
            continue;
        }
        if (isdigit(*character))
        {
            STACK_ERROR(push(&digits, (int)*character - '0'));
        }
        else
        {
            int second = top(digits, errorCode);
            STACK_ERROR(*errorCode);
            pop(&digits);

            int first = top(digits, errorCode);
            STACK_ERROR(*errorCode);
            pop(&digits);

            switch (*character)
            {
            case '+':
                STACK_ERROR(push(&digits, first + second));
                break;
            case '/':
                STACK_ERROR(push(&digits, first / second));
                break;
            case '*':
                STACK_ERROR(push(&digits, first * second))
                break;
            case '-':
                STACK_ERROR(push(&digits, first - second));
                break;
            default:
                break;
            }
        }
    }

    int answer = top(digits, errorCode);
    pop(&digits);

    if (!isEmpty(digits))
    {
        *errorCode = error;
    }

    return answer;
}
