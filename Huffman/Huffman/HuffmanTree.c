#include <stdlib.h>
#include <string.h>

#include "HuffmanTree.h"

typedef struct Node
{
    char value;
    size_t count;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

struct HuffmanTree
{
    Node* root;
};

int getCount(HuffmanTree* tree)
{
    return tree != NULL ? tree->root->count : 0;
}

HuffmanTree* makeLeaf(const char value, const size_t count)
{
    Node* leaf = (Node*)calloc(1, sizeof(Node));
    leaf->value = value;
    leaf->count = count;
    HuffmanTree* newTree = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    newTree->root = leaf;
    return newTree;
}

HuffmanTree* makeTree(HuffmanTree** const tree1, HuffmanTree** const tree2)
{
    HuffmanTree* newTree = makeLeaf('\0', getCount(*tree1) + getCount(*tree2));
    newTree->root->leftChild = (*tree1)->root;
    newTree->root->rightChild = (*tree2)->root;

    free(*tree1);
    free(*tree2);
    *tree1 = NULL;
    *tree2 = NULL;

    return newTree;
}

static void makeCode(size_t position, bool code[256], Node* current, Code* codeTable)
{
    if (current->leftChild == NULL)
    {
        codeTable[current->value].size = position;
        memcpy_s(codeTable[current->value].code, 256 * sizeof(bool), code, 256 * sizeof(bool));
        return;
    }
    code[position] = 0;
    makeCode(position + 1, code, current->leftChild, codeTable);
    code[position] = 1;
    makeCode(position + 1, code, current->rightChild, codeTable);
}

Code* createCodeTable(const HuffmanTree* const tree)
{
    Code* table = (Code*)calloc(256, sizeof(Code));
    bool code[256] = { false };
    makeCode(0, code, tree->root, table);
    return table;
}
