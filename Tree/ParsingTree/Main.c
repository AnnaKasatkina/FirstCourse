#include "Utility.h"
#include "ParsingTree.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define NAME "Expretion.txt"

int main(void)
{
    /*if (!resultTests())
    {
        printf("Test error!");
        return ERROR;
    }*/

    size_t length = 0;
    char* string = getStringFromFile(NAME);

    if (string == NULL)
    {
        printf("Error!");
        return ERROR;
    }

    Node* tree = NULL;

    buildTree(&string, &tree);
    printf(getStringFromTree(tree));

    return 0;
}
