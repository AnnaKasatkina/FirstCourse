#pragma once

#include <stdio.h>
#include "ParsingTree.h"

/* ��������:
    FILE* file;
    char name[] = "ParsingTree.dot";
    if ((file = fopen(name, "w+")) == NULL)
    {
        printf("�� ������� ������� ����");
        getchar();
        return 0;
    }
    printGraph(tree, file);

    fclose(file);

   ����� ������� �

   size_t number;

   � ��������� ������ ��� ��������� .dot */

void printGraph(Node* tree, FILE* stream);