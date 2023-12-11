#pragma once

#include <stdbool.h>

#define SIZE 100

typedef enum
{
    ok,
    error,
    outOfMemory,
    fileError
} ErrorCode;

typedef struct
{
    char* name;
    char* phone;
} PhoneBookEntry;

typedef struct
{
    PhoneBookEntry* entries[SIZE];
    size_t length;
} PhoneBook;

typedef bool (*CompareFunc) (const PhoneBookEntry*, const char* const);

bool compareName(const PhoneBookEntry* const elementOne, const char* const elementTwo);

bool comparePhone(const PhoneBookEntry* const elementOne, const char* const elementTwo);

void addEntry(PhoneBook* const buffer, const char* const name, const char* const phone, ErrorCode* errorCode);

PhoneBookEntry* searchElement(const PhoneBook* const buffer, const char* const name, CompareFunc compare);

void deletePhoneBook(PhoneBook* const buffer);

PhoneBook* readPhoneBook(const char* const nameFile);

void saveFile(const PhoneBook* const buffer);

void printAllEntry(const PhoneBook* const buffer);
