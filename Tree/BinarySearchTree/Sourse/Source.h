#pragma once

#include <stdio.h>
#include "..\BinaryTree.h"

/* Добавить: 
    FILE* file;
    char name[] = "BinatyTree.dot";
    if ((file = fopen(name, "w+")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    printGraph(tree, file);

    fclose(file);

   перед выходом, для получения .dot */

void printGraph(const Node* const tree, FILE* stream);
