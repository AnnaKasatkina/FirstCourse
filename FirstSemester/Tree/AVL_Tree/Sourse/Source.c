#include <stdio.h>
#include "Source.h"

void printList(int key, int nullcount, FILE* stream)
{
    fprintf(stream, " null%d [shape=point];\n", nullcount);
    fprintf(stream, " %d -> null%d;\n", key, nullcount);
}

void printNode(Node* node, FILE* stream)
{
    static int count = 0;

    if (node->leftChild)
    {
        fprintf(stream, " %s -> %s;\n", node->element->key, node->leftChild->element->key);
        printNode(node->leftChild, stream);
    }

    if (node->rightChild)
    {
        fprintf(stream, " %s -> %s;\n", node->element->key, node->rightChild->element->key);
        printNode(node->rightChild, stream);
    }
}

void printGraph(const Node* const tree, FILE* stream)
{
    fprintf(stream, "digraph {\n");
    fprintf(stream, " node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->rightChild && !tree->leftChild)
        fprintf(stream, " %s;\n", tree->element->key);
    else
        printNode(tree, stream);

    fprintf(stream, "}\n");
}
