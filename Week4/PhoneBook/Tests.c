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

static bool testAddEntry(PhoneBookEntry* const buffer, size_t* length)
{
    const char* const name = "Derek Parlane Stein Jackson Hunter McCloy Kennedy";
    const char* const phone = "+7 (931) 884-66-69";

    addEntry(buffer, *length, name, phone);

    return strcmp(buffer[*length].name, name) == 0 && strcmp(buffer[*length].phone, phone) == 0;
}

static bool testSearchPhoneTrue(PhoneBookEntry* const buffer, const size_t length)
{
    const char* const name = "Michael  ";

    return searchPhone(buffer, length, name) != -1;
}

static bool testSearchPhoneFalse(PhoneBookEntry* const buffer, const size_t length)
{
    const char* const name = "Anna";

    return searchPhone(buffer, length, name) == -1;
}

static bool testSearchNameTrue(PhoneBookEntry* const buffer, const size_t length)
{
    const char* const phone = "  +7 (941) 284-22-18";

    return searchName(buffer, length, phone) != -1;
}

static bool testSearchNameFalse(PhoneBookEntry* const buffer, const size_t length)
{
    const char* const phone = "800 - 555 - 355";

    return searchName(buffer, length, phone) == -1;
}

bool resultTests(void)
{
    size_t length = 0;
    PhoneBookEntry* buffer = readPhoneBook("Test.txt", &length);

    const bool answer1 = testAddEntry(buffer, &length);
    const bool answer2 = testSearchPhoneTrue(buffer, length);
    const bool answer3 = testSearchPhoneFalse(buffer, length);
    const bool answer4 = testSearchNameTrue(buffer, length);
    const bool answer5 = testSearchNameFalse(buffer, length);


    printResultTest(answer1, "Add Entry");
    printResultTest(answer2, "Search Phone True");
    printResultTest(answer3, "Search Phone False");
    printResultTest(answer4, "Search Name True");
    printResultTest(answer5, "Search Name False");
    printf("\n");

    return answer1 && answer2 && answer3 && answer4 && answer5;
}
