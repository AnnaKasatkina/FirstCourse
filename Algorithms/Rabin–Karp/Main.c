#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BASE 31
#define NUMBER 2147483647

bool compareString(const char* const string1, const char* const string2, const size_t length)
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

size_t calculateHash(const char* const string, const size_t lengthString)
{
    size_t result = (int)string[0];

    for (size_t i = 1; i < lengthString; ++i)
    {
        result = (BASE * result + string[i]) % NUMBER;
    }
    return result % NUMBER;
}

size_t searchPattern(const char* const string, const char* const pattern, const size_t lengthString)
{
    size_t lengthPattern = strlen(pattern);
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
                return index;
            }
        }
        currentHash = (BASE * (currentHash - string[index] * maxDegree) + string[index + lengthPattern]) % NUMBER;
    }

    return -1;
}

int main()
{
    char* string = "Hello World!";
    printf("String: %s\n", string);
    char* pattern = "llo";
    printf("Pattern: %s\n", pattern);
    size_t lengthString = strlen(string);

    size_t answer = searchPattern(string, pattern, lengthString);

    printf(answer == -1 ? "Not found" : "index: %d", answer);
}
