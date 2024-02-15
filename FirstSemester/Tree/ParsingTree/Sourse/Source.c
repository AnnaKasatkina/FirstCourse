#include <stdio.h>
#include "Source.h"

void printNode(Node* node, FILE* stream)
{
    if (node->leftChild)
    {
        fprintf(stream, " Node%zd -> Node%zd;\n", node->number, node->leftChild->number);
        printNode(node->leftChild, stream);
    }

    if (node->rightChild)
    {
        fprintf(stream, " Node%zd -> Node%zd;\n", node->number, node->rightChild->number);
        printNode(node->rightChild, stream);
    }
}

static void printComment(Node* tree, FILE* stream, size_t* nodeCount)
{
    if (tree)
    {
        fprintf(stream, " Node%zd[label = \"%c\"];\n", *nodeCount, tree->value);
        tree->number = *nodeCount;
        ++(*nodeCount);
        printComment(tree->leftChild, stream, nodeCount);
        printComment(tree->rightChild, stream, nodeCount);
    }
}

void printGraph(Node* tree, FILE* stream)
{
    fprintf(stream, "digraph {\n");
    fprintf(stream, " node [fontname=\"Arial\"];\n");

    size_t nodeCount = 0;
    printComment(tree, stream, &nodeCount);

    tree == NULL ? fprintf(stream, "\n") : printNode(tree, stream);

    fprintf(stream, "}\n");
}