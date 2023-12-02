﻿#include "Rabin–Karp.h"

#include <string.h>

#define BASE 31
#define NUMBER 2147483647

static bool compareString(const wchar_t* const string1, const wchar_t* const string2, 
    const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (string1[i] != string2[i])
        {
            return false;
        }
    }
    return true;
}

static size_t calculateHash(const wchar_t* const string, const size_t lengthString)
{
    size_t result = (int)string[0];

    for (size_t i = 1; i < lengthString; ++i)
    {
        result = (BASE * result + string[i]) % NUMBER;
    }
    return result % NUMBER;
}

bool searchPattern(const wchar_t* const string, const wchar_t* const pattern, 
    const size_t lengthString, const size_t lengthPattern)
{
    size_t patternHash = calculateHash(pattern, lengthPattern);
    size_t currentHash = calculateHash(string, lengthPattern);
    size_t maxDegree = 1;

    for (size_t i = 0; i < lengthPattern - 1; i++)
    {
        maxDegree = (maxDegree * BASE) % NUMBER;
    }

    for (size_t index = 0; index + lengthPattern <= lengthString; ++index)
    {
        if (patternHash == currentHash)
        {
            if (compareString(pattern, &(string[index]), lengthPattern))
            {
                return true;
            }
        }
        currentHash = BASE * (currentHash - string[index] * maxDegree) % NUMBER;
        currentHash += string[index + lengthPattern] % NUMBER;
    }

    return false;
}
