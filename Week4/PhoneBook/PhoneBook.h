#pragma once

#define LEN 30
typedef struct
{
    char* name;
    char* phone;
} PhoneBookEntry;

void choose(const int choice, PhoneBookEntry* const buffer, const size_t length);
