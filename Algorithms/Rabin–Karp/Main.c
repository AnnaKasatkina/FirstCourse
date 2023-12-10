#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "Rabin–Karp.h"
#include "Utility.h"

#define NAME_FILE "Text.txt"
#define ERROR_CODE -1

int main(void)
{
    setlocale(LC_ALL, ".1251");

    size_t lengthString = 0;
    wchar_t* string = getStringFromFile(NAME_FILE, &lengthString);
    if (string == NULL)
    {
        return ERROR_CODE;
    }

    printf("String: %ls\n", string);

    printf("Pattern: ");
    size_t lengthPattern = 0;
    wchar_t* pattern = getString(stdin, &lengthPattern);
    printf("\n");

    long answer = searchPattern(string, pattern, lengthString, lengthPattern);

    printf(answer == NOT_FOUND ? "Not found!\n" : "Found!\nPosition: %ld\n", answer);
}
