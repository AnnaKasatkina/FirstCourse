#include "Tests.h"
#include "HashTable.h"
#include "Utility.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void printResultTest(const bool result, const char* const nameTest)
{
    if (result)
    {
        printf("Test %s is OK\n", nameTest);
    }
    else
    {
        printf("Test %s failed with an error\n", nameTest);
    }
}

static bool testCorrectValues(HashTable* hashTable)
{
    char* string = "to";
    size_t count = 4;

    return findElement(hashTable, string, count);
}

static bool testIncorrectValues(HashTable* hashTable)
{
    char* string = "Anna";
    size_t count = 1;

    return !findElement(hashTable, string, count);
}

static bool testIncorrectCount(HashTable* hashTable)
{
    char* string = "skills";
    size_t count = 2;

    return !findElement(hashTable, string, count);
}

bool testResult(void)
{
    List* list = getStringFromFile("Tests/testText.txt");
    if (list == NULL)
    {
        return false;
    }

    HashTable* hashTable = makeHashTable(list, list->size);
    if (hashTable == NULL)
    {
        freeList(&list);
        return false;
    }

    bool result1 = testCorrectValues(hashTable);
    bool result2 = testIncorrectValues(hashTable);
    bool result3 = testIncorrectCount(hashTable);

    printResultTest(result1, "Correct Values");
    printResultTest(result2, "Incorrect Values");
    printResultTest(result3, "Incorrect Count");
    printf("\n");

    freeList(&list);
    deleteHashTable(&hashTable);

    return result1 && result2 && result3;
}
