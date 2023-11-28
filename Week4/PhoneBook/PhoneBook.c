#include "PhoneBook.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void addEntry(PhoneBookEntry* const buffer, const size_t length,
    const char* const name, const char* const phone)
{
    buffer[length].name = name;
    buffer[length].phone = phone;
}

size_t searchPhone(const PhoneBookEntry* const buffer,
    const size_t length, const char* const name)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (!strcmp(buffer[i].name, name))
        {
            return i;
        }
    }
    return -1;

}

size_t searchName(const PhoneBookEntry* const buffer,
    const size_t length, const char* const phone)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (!strcmp(buffer[i].phone, phone))
        {
            return i;
        }
    }
    return -1;
}
