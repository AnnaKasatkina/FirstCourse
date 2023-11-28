#pragma once

typedef struct
{
    char* name;
    char* phone;
} PhoneBookEntry;

void addEntry(PhoneBookEntry* const buffer, const size_t length,
    const char* const name, const char* const phone);

size_t searchPhone(const PhoneBookEntry* const buffer,
    const size_t length, const char* const name);

size_t searchName(const PhoneBookEntry* const buffer,
    const size_t length, const char* const phone);
