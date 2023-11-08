#pragma once

typedef struct
{
    char name[30];
    char phone[30];
} PhoneBookEntry;

void addEntry(PhoneBookEntry* buffer, int length);

void printAllEntry(PhoneBookEntry* buffer, int length);

void searchPhone(PhoneBookEntry* buffer, int length);

void searchName(PhoneBookEntry* buffer, int length);

void saveFile(PhoneBookEntry* buffer, int length);

void choose(int choice, PhoneBookEntry* buffer, int length);