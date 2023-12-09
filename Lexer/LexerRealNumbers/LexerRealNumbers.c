#include "LexerRealNumbers.h"

#include <stdbool.h>
#include <ctype.h>

static bool startMethod(const char* const string, enum State* state)
{
    if (isdigit(*string))
    {
        *state = INTEGER;
        return true;
    }
    else
    {
        return false;
    }
}

static bool integerMethod(const char* const string, enum State* state)
{
    if (!isdigit(*string))
    {
        if (*string == '.')
        {
            *state = DECIMAL;
        }
        else if (*string == 'e' || *string == 'E')
        {
            *state = EXPONENT_SIGN;
        }
        else
        {
            return false;
        }
    }
    return true;
}

static bool decimalMethod(const char* const string, enum State* state)
{
    if (!isdigit(*string))
    {
        if (*string == 'e' || *string == 'E')
        {
            *state = EXPONENT_SIGN;
        }
        else
        {
            return false;
        }
    }
    return true;
}

static bool exponentSignMethod(const char* const string, enum State* state)
{
    if (*string == '+' || *string == '-')
    {
        *state = EXPONENT_DIGIT;
    }
    else if (isdigit(*string))
    {
        *state = EXPONENT_DIGIT;
    }
    else
    {
        return false;
    }
    return true;
}

int lexer(const char* string)
{
    enum State state = START;

    while (*string != '\0')
    {
        switch (state)
        {
        case START:

            if (!startMethod(string, &state))
            {
                return false;
            }
            break;

        case INTEGER:

            if (!integerMethod(string, &state))
            {
                return false;
            }
            break;

        case DECIMAL:

            if (!decimalMethod(string, &state))
            {
                return false;
            }
            break;

        case EXPONENT_SIGN:

            if (!exponentSignMethod(string, &state))
            {
                return false;
            }
            break;

        case EXPONENT_DIGIT:
            if (!isdigit(*string))
            {
                return false;
            }
            break;
        }

        string++;
    }

    return (state == INTEGER || state == DECIMAL || state == EXPONENT_DIGIT);
}
