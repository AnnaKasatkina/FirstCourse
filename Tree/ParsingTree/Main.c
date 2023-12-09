#include "ParsingTree.h"
#include "Tests.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define STRING_ERROR "Error!"
#define NAME_FILE "Expression.txt"

int main(void)
{
    if (!testResult())
    {
        printf(STRING_ERROR);
        return ERROR;
    }

    FILE* file = fopen(NAME_FILE, "r");
    if (file == NULL)
    {
        printf(STRING_ERROR);
        return ERROR;
    }

    Node* tree = buildTree(file);
    fclose(file);

    printf("Tree: ");
    printTree(tree);
    printf("\n");

    ErrorCode errorCode = ok;
    int result = calculateResult(tree, &errorCode);
    if (errorCode != ok)
    {
        printf(STRING_ERROR);
        return ERROR;
    }
    printf("Result: %d\n", result);

    deleteTree(&tree);

    return 0;
}
