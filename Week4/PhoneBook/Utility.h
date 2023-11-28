#pragma once

#include "PhoneBook.h"

typedef enum ErrorCode
{
    ok,
    stackIsEmpty,
    outOfMemory
} ErrorCode;

PhoneBookEntry* readPhoneBook(const char* const nameFile, size_t* length);

char* getString(void);

void saveFile(const PhoneBookEntry* const buffer, const size_t length);
