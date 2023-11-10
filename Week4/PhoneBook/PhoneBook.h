#pragma once

#define LEN 30
typedef struct
{
    char name[LEN];
    char phone[LEN];
} PhoneBookEntry;

void addEntry(PhoneBookEntry* buffer, size_t length);

void printAllEntry(PhoneBookEntry* buffer, size_t length);

void searchPhone(PhoneBookEntry* buffer, size_t length);

void searchName(PhoneBookEntry* buffer, size_t length);

void saveFile(PhoneBookEntry* buffer, size_t length);

void choose(int choice, PhoneBookEntry* buffer, size_t length);