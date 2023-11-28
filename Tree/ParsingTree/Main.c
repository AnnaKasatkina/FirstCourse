#include "Utility.h"
#include "ParsingTree.h"
#include "Tests.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define NAME "Expretion.txt"

int main(void)
{
    if (!testResult())
    {
        printf("Test error!");
        return ERROR;
    }

    char* string = getStringFromFile(NAME);

    if (string == NULL)
    {
        printf("Error!");
        return ERROR;
    }

    Node* tree = NULL;

    buildTree(&string, &tree);
    char* answer = getStringFromTree(tree);

    printf(answer);
    printf("\n");

    ErrorCode errorCode = ok;
    int result = calculateResult(answer, &errorCode);

    addBrackets(&answer);

    return 0;
}
