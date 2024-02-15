#pragma once

#include <stdio.h>
#include "ParsingTree.h"

/* Добавить:
    FILE* file;
    char name[] = "ParsingTree.dot";
    if ((file = fopen(name, "w+")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    printGraph(tree, file);

    fclose(file);

   перед выходом и

   size_t number;

   в структуру дерева для получения .dot */

void printGraph(Node* tree, FILE* stream);