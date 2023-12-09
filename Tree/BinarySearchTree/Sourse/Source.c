#include <stdio.h>
#include "Source.h"
#include "..\BinaryTree.h"

void printList(int key, int nullcount, FILE* stream)
{
    fprintf(stream, " null%d [shape=point];\n", nullcount);
    fprintf(stream, " %d -> null%d;\n", key, nullcount);
}

void printNode(const Node* const node, FILE* stream)
{
    static int count = 0;

    if (node->leftChild)
    {
        fprintf(stream, " %d -> %d;\n", node->element->key, node->leftChild->element->key);
        printNode(node->leftChild, stream);
    }
    else
        printList(node->element->key, count++, stream);

    if (node->rightChild)
    {
        fprintf(stream, " %d -> %d;\n", node->element->key, node->rightChild->element->key);
        printNode(node->rightChild, stream);
    }
    else
        printList(node->element->key, count++, stream);
}

static void printComment(const Node* const tree, FILE* stream)
{
    if (tree)
    {
        fprintf(stream, " %d [label=\"%s\", xlabel=\"%d\"];\n", tree->element->key, tree->element->value, tree->element->key);
        printComment(tree->leftChild, stream);
        printComment(tree->rightChild, stream);
    }
}

void printGraph(const Node* const tree, FILE* stream)
{
    fprintf(stream, "digraph {\n");
    fprintf(stream, " node [fontname=\"Arial\"];\n");

    printComment(tree, stream);

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->rightChild && !tree->leftChild)
        fprintf(stream, " %d;\n", tree->element->key);
    else
        printNode(tree, stream);

    fprintf(stream, "}\n");
}
