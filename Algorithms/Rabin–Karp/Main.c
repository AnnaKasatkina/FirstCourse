#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>

#include "Rabin–Karp.h"
#include "Utility.h"

#define NAME_FILE "Text.txt"
#define ERROR_CODE -1

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    size_t lengthString = 0;
    wchar_t* string = getStringFromFile(NAME_FILE, &lengthString);
    if (string == NULL)
    {
        return ERROR_CODE;
    }

    printf("String: %ls\n", string);

    printf("Pattern: ");
    size_t lengthPattern = 0;
    wchar_t* pattern = getString(&lengthPattern);
    printf("\n");

    bool answer = searchPattern(string, pattern, lengthString, lengthPattern);

    printf(answer ? "Found!\n" : "Not found!\n");
}
