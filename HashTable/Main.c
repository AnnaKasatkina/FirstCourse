#include "List.h"
#include "Utility.h"
#include "UserModule.h"

#define ERROR -1

int main(void)
{
    if (!testResult())
    {
        printf("Test error!");
        return ERROR;
    }

    List* list = getStringFromFile("Text.txt");
    if (list == NULL)
    {
        printf("Error!");
        return ERROR;
    }

    List** hashTable = makeHashTable(list);
    printHashTableStatus(hashTable, list->size);
    printHashTableElements(hashTable, list);

    return 0;
}
