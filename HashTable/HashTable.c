#include "HashTable.h"

#include <string.h>

#define BASE 31

size_t calculateHash(const char* const string, const size_t lengthString, const size_t number)
{
    size_t result = (int)string[0];

    for (size_t i = 1; i < lengthString; ++i)
    {
        result = (BASE * result + string[i]);
    }
    return result % number;
}

List** makeHashTable(const List* const list)
{
    size_t sizeOfTable = list->size;
    ListElement* currentElement = list->begin;
    List** hashTable = (List**)calloc(sizeOfTable, sizeof(List));

    for (size_t i = 0; i < sizeOfTable; i++)
    {
        size_t hash = calculateHash(currentElement->value, currentElement->length, sizeOfTable);
        if (hashTable[hash] == NULL)
        {
            hashTable[hash] = initList();
        }
        pushBack(hashTable[hash], currentElement->value, currentElement->length);

        if (currentElement->next != NULL)
        {
            currentElement = currentElement->next;
        }
    }

    return hashTable;
}

void countHashTableStatus(const List* const* const hashTable, const size_t sizeOfTable,
    float* const fillFactor, size_t* const maxLength, size_t* const averageLength)
{
    size_t countNotEmpty = 0;
    size_t sumLength = 0;

    for (size_t i = 0; i < sizeOfTable; i++)
    {
        if (hashTable[i] != NULL)
        {
            ++countNotEmpty;
            sumLength += hashTable[i]->size;
            *maxLength = max(*maxLength, hashTable[i]->size);
        }
    }

    *fillFactor = (float)countNotEmpty / sizeOfTable; 
    *averageLength = sumLength / sizeOfTable;
}

size_t* countHashTableElements(const List* const* const hashTable, const List * const list)
{
    size_t sizeOfTable = list->size;
    ListElement* currentElement = list->begin;
    size_t* count = (size_t*)calloc(sizeOfTable, sizeof(size_t));

    for (size_t i = 0; i < sizeOfTable; i++)
    {
        size_t hash = calculateHash(currentElement->value, currentElement->length, sizeOfTable);

        if (hashTable[hash] == NULL)
        {
            break;
        }

        ListElement* cmpElement = hashTable[hash]->begin;

        while (cmpElement != NULL)
        {
            if (strcmp(cmpElement->value, currentElement->value) == 0)
            {
                ++count[i];
            }
            cmpElement = cmpElement->next;
        }
        currentElement = currentElement->next;
    }
    return count;
}
