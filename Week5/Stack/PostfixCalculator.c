#include "Stack.h"
#include "PostfixCalculator.h"
#include "Utility.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int postfixCalculator(char* string, ErrorCode* errorCode)
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
            push(&digits, (int)*character - '0');
        }
        else
        {
            int second = top(digits, errorCode);
            pop(&digits);

            int first = top(digits, errorCode);
            pop(&digits);

            switch (*character)
            {
            case '+':
                push(&digits, first + second);
                break;
            case '/':
                push(&digits, first / second);
                break;
            case '*':
                push(&digits, first * second);
                break;
            case '-':
                push(&digits, first - second);
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
