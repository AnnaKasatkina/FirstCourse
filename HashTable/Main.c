#include "List.h"
#include "Utility.h"
#include "Tests.h"
#include "UserModule.h"

#define ERROR -1
#define ERROR_STRING "Error!"

int main(void)
{
    if (!testResult())
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    List* list = getStringFromFile("Text.txt");
    if (list == NULL)
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    HashTable* hashTable = makeHashTable(list, list->size);
    if (hashTable == NULL)
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    printHashTable(hashTable);

    freeList(list);
    deleteHashTable(hashTable);

    return 0;
}
