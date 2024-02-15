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
    if (tree == NULL)
    {
        fclose(file);
        printf(STRING_ERROR);
        return ERROR;
    }
    fclose(file);

    ErrorCode errorCode = ok;
    printf("Tree: ");
    printTree(tree, &errorCode);
    if (errorCode != ok)
    {
        deleteTree(&tree);
        printf(STRING_ERROR);
        return ERROR;
    }
    printf("\n");

    int result = calculateResult(tree, &errorCode);
    if (errorCode != ok)
    {
        deleteTree(&tree);
        printf(STRING_ERROR);
        return ERROR;
    }
    printf("Result: %d\n", result);

    deleteTree(&tree);

    return 0;
}
