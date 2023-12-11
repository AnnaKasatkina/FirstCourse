#include "HashTable.h"

#include <string.h>
#include <stdlib.h>

#define BASE 31

HashTable* initializeHashTable(const size_t sizeOfTable) 
{
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL)
    {
        return NULL;
    }

    hashTable->data = (List**)calloc(sizeOfTable, sizeof(List*));
    if (hashTable->data == NULL)
    {
        return NULL;
    }
    hashTable->sizeOfTable = sizeOfTable;

    for (size_t i = 0; i < sizeOfTable; ++i) 
    {
        hashTable->data[i] = (List*)calloc(1, sizeof(List));
        if (hashTable->data[i] == NULL)
        {
            return NULL;
        }
    }

    return hashTable;
}

static size_t calculateHash(const char* const string, const size_t lengthString, const size_t number)
{
    size_t result = (int)string[0];

    for (size_t i = 1; i < lengthString; ++i)
    {
        result = (BASE * result + string[i]);
    }
    return result % number;
}

HashTable* makeHashTable(const List* const list, size_t sizeOfTable)
{
    ErrorCode errorCode = ok;
    ListElement* currentElement = list->begin;
    HashTable* hashTable = initializeHashTable(sizeOfTable);

    for (size_t i = 0; i < list->size; i++)
    {
        size_t hash = calculateHash(currentElement->value, currentElement->length, sizeOfTable);
        countDuplicates(hashTable->data[hash], currentElement->value, currentElement->length, &errorCode);
        if (errorCode != ok)
        {
            return NULL;
        }
        currentElement = currentElement->next;
    }
    return hashTable;
}

void countHashTableStatus(HashTable* hashTable, float* const fillFactor,
    size_t* const maxLength, size_t* const averageLength)
{
    size_t countNotEmpty = 0;
    size_t sumLength = 0;

    for (size_t i = 0; i < hashTable->sizeOfTable; i++)
    {
        if (hashTable->data[i] != NULL)
        {
            ++countNotEmpty;
            sumLength += hashTable->data[i]->size;
            *maxLength = max(*maxLength, hashTable->data[i]->size);
        }
    }

    *fillFactor = (float)countNotEmpty / hashTable->sizeOfTable;
    *averageLength = sumLength / hashTable->sizeOfTable;
}

void deleteHashTable(HashTable* hashTable)
{
    for (size_t i = 0; i < hashTable->sizeOfTable; ++i) 
    {
        ListElement* currentElement = hashTable->data[i]->begin;
        while (currentElement != NULL)
        {
            ListElement* nextElement = currentElement->next;
            free(currentElement->value);
            free(currentElement);
            currentElement = nextElement;
        }
        free(hashTable->data[i]);
    }
    free(hashTable->data);
    free(hashTable);
}
