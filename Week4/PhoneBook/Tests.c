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

static bool testAddEntry(PhoneBook* const buffer)
{
    const char* const name = "Derek Parlane Stein Jackson Hunter McCloy Kennedy";
    const char* const phone = "+7 (931) 884-66-69";

    addEntry(buffer, name, phone);
    size_t length = buffer->length;

    return strcmp(buffer->entries[length]->name, name) == 0 && strcmp(buffer->entries[length]->phone, phone) == 0;
}

static bool testSearchPhoneTrue(PhoneBook* const buffer)
{
    const char* const name = "Michael ";
    const char* const phone = " +7 (924) 156-40-24";

    return strcmp(searchElement(buffer, name, compareName)->phone, phone) == 0;
}

static bool testSearchPhoneFalse(PhoneBook* const buffer)
{
    const char* const name = "Anna ";

    return searchElement(buffer, name, compareName) == NULL;
}

static bool testSearchNameTrue(PhoneBook* const buffer)
{
    const char* const name = "James ";
    const char* const phone = " +7 (941) 284-22-18";

    return strcmp(searchElement(buffer, phone, comparePhone)->name, name) == 0;
}

static bool testSearchNameFalse(PhoneBook* const buffer)
{
    const char* const phone = " 800 - 555 - 355";

    return searchElement(buffer, phone, comparePhone) == NULL;
}

bool resultTests(void)
{
    PhoneBook* buffer = readPhoneBook("Test.txt");
    if (buffer == NULL)
    {
        return false;
    }

    const bool answer1 = testAddEntry(buffer);
    const bool answer2 = testSearchPhoneTrue(buffer);
    const bool answer3 = testSearchPhoneFalse(buffer);
    const bool answer4 = testSearchNameTrue(buffer);
    const bool answer5 = testSearchNameFalse(buffer);


    printResultTest(answer1, "Add Entry");
    printResultTest(answer2, "Search Phone True");
    printResultTest(answer3, "Search Phone False");
    printResultTest(answer4, "Search Name True");
    printResultTest(answer5, "Search Name False");
    printf("\n");

    return answer1 && answer2 && answer3 && answer4 && answer5;
}
