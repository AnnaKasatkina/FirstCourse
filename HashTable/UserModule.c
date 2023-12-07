#include "UserModule.h"

void printHashTableStatus(const List* const* const hashTable, const size_t sizeOfTable)
{
    float fillFactor = 0.00;
    size_t maxLength = 0;
    size_t averageLength = 0;

    countHashTableStatus(hashTable, sizeOfTable, &fillFactor, &maxLength, &averageLength);

    printf("There are %zd words in the text\n"
        "The hash table's fill factor is %.2f\n"
        "The maximum length of the list in segment is %zd\n"
        "The average length of the list in segment is %zd\n",
        sizeOfTable, fillFactor, maxLength, averageLength);
}

void printHashTableElements(const List* const* const hashTable, const List* const list)
{
    size_t* count = countHashTableElements(hashTable, list);
    ListElement* currentElement = list->begin;

    for (size_t i = 0; i < list->size; i++)
    {
        printf("%s - %zd\n", currentElement->value, count[i]);
        currentElement = currentElement->next;
    }
}
