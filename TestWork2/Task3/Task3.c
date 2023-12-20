#include <ctype.h>
#include <stdlib.h>

#include "Task3.h"

typedef enum
{
    START,
    IN_IDENTIFIER,
    ERROR
} State;

bool processString(const char* string)
{
    State state = START;

    for (; *string != '\0'; ++string)
    {
        switch (state)
        {
        case START:
            state = isalpha(*string) ? IN_IDENTIFIER : ERROR;
            break;

        case IN_IDENTIFIER:
            state = (isalnum(*string) || *string == '_') ? IN_IDENTIFIER : ERROR;
            break;

        case ERROR:
            return false;
        }
    }

    return state == IN_IDENTIFIER;
}
