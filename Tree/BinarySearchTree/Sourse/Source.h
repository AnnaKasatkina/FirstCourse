#pragma once

#include <stdio.h>
#include "..\BinaryTree.h"

/* ��������: 
    FILE* file;
    char name[] = "BinatyTree.dot";
    if ((file = fopen(name, "w+")) == NULL)
    {
        printf("�� ������� ������� ����");
        getchar();
        return 0;
    }
    printGraph(tree, file);

    fclose(file);

   ����� �������, ��� ��������� .dot */

void printGraph(const Node* const tree, FILE* stream);
