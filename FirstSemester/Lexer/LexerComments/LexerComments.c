#include "LexerComments.h"

#include <stdlib.h>

#define SIZE 6

typedef struct
{
    int currentState;
    char input;
    int nextState;
} StateTable;

typedef enum
{
    START,
    SLASH,
    ASTERISK,
    IN_COMMENT,
    END_COMMENT,
    ERROR
} State;

static StateTable* makeStateTable(void)
{
    FILE* file = fopen("StateTable.txt", "r");
    if (file == NULL)
    {
        return NULL;
    }

    StateTable* stateTable = (StateTable*)calloc(SIZE, sizeof(StateTable));
    if (stateTable == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < SIZE; i++)
    {
        if (fscanf(file, "%d, %c, %d", &stateTable[i].currentState, 
            &stateTable[i].input, &stateTable[i].nextState) != 3)
        {
            return NULL;
        }
    }

    return stateTable;
}

static void startMethod(const char character, State* state)
{
    if (character == '/')
    {
        *state = SLASH;
    }
}

static void slashMethod(const char character, State* state)
{
    if (character == '*')
    {
        *state = IN_COMMENT;
        printf("/ ");
        return;
    }
    *state = START;
}

static void inCommentMethod(const char character, State* state)
{
    if (character == '*')
    {
        *state = END_COMMENT;
        return;
    }
    putchar(character);
}

static void endCommentMethod(const char character, State* state)
{
    if (character == '/')
    {
        putchar(character);
        printf("\n");
        *state = START;
        return;
    }
    if (character == '*')
    {
        putchar(character);
        return;
    }
    *state = IN_COMMENT;
    putchar(character);
}

void processComment(FILE* file)
{
    StateTable* stateTable = makeStateTable();
    State state = START;
    char character = ' ';

    while ((character = fgetc(file)) != EOF)
    {
        switch (state)
        {
        case START:
            startMethod(character, &state);
            break;

        case SLASH:
            slashMethod(character, &state);
            break;

        case IN_COMMENT:
            inCommentMethod(character, &state);
            break;

        case END_COMMENT:
            endCommentMethod(character, &state);
            break;

        case ERROR:
            break;
        }
    }

    if (state == IN_COMMENT)
    {
        fprintf(stderr, "Error: Unterminated comment\n");
    }
}
