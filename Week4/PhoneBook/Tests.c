#include "Tests.h"
#include "PhoneBook.h"
#include "Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void printResultTest(const bool rezult, const char* const nameTest)
{
    if (rezult)
    {
        printf("Test %s is OK\n", nameTest);
    }
    else
    {
        printf("Test %s failed with an error\n", nameTest);
    }
}

static bool testsCaseSearch(PhoneBook* const buffer, const char* const string, CompareFunc compare, bool result)
{
    if (searchElement(buffer, string, compare) == NULL)
    {
        return !result;
    }
    return result;
}

static bool testAddEntry(PhoneBook* const buffer)
{
    ErrorCode errorCode = ok;
    const char* const name = "Derek Parlane Stein Jackson Hunter McCloy Kennedy";
    const char* const phone = "+7 (931) 884-66-69";

    char* copyName = _strdup(name);
    if (copyName == NULL)
    {
        return false;
    }
    char* copyPhone = _strdup(phone);
    if (copyPhone == NULL)
    {
        return false;
    }

    addEntry(buffer, copyName, copyPhone, &errorCode);
    if (errorCode != ok)
    {
        return false;
    }
    size_t length = buffer->length;

    return strcmp(buffer->entries[length]->name, name) == 0 && strcmp(buffer->entries[length]->phone, phone) == 0;
}

bool resultTests(void)
{
    PhoneBook* buffer = readPhoneBook("Test.txt");
    if (buffer == NULL)
    {
        return false;
    }

    const bool answer1 = testAddEntry(buffer);
    const bool answer2 = testsCaseSearch(buffer, "Michael ", compareName, true);
    const bool answer3 = testsCaseSearch(buffer, "Anna ", compareName, false);
    const bool answer4 = testsCaseSearch(buffer, " +7 (941) 284-22-18", comparePhone, true);
    const bool answer5 = testsCaseSearch(buffer, " 800 - 555 - 355", comparePhone, false);


    printResultTest(answer1, "Add Entry");
    printResultTest(answer2, "Search Phone True");
    printResultTest(answer3, "Search Phone False");
    printResultTest(answer4, "Search Name True");
    printResultTest(answer5, "Search Name False");
    printf("\n");

    deletePhoneBook(buffer);

    return answer1 && answer2 && answer3 && answer4 && answer5;
}
