#include <stdio.h>

#include "LexerComments.h"

#define ERROR -1

int main(void) 
{
    FILE* file = fopen("input.c", "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        return ERROR;
    }

    processComment(file);

    fclose(file);
    return 0;
}
