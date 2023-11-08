#pragma once

#define LEN 30
typedef struct
{
    char name[LEN];
    char phone[LEN];
} PhoneBookEntry;

void addEntry(PhoneBookEntry* buffer, int length);

void printAllEntry(PhoneBookEntry* buffer, int length);

void searchPhone(PhoneBookEntry* buffer, int length);

void searchName(PhoneBookEntry* buffer, int length);

void saveFile(PhoneBookEntry* buffer, int length);

void choose(int choice, PhoneBookEntry* buffer, int length);