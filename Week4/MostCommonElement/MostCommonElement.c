#include "MostCommonElement.h"
#include "Sort.h"

int findTheMostCommon(const int* const array, const size_t length)
{
    quickSort(array, array + length);
    size_t count = 1;
    size_t maxCount = 0;
    int answer = array[0];
    for (size_t i = 1; i < length; ++i)
    {
        count = array[i] == array[i - 1] ? count + 1 : 1;

        if (count >= maxCount)
        {
            answer = array[i];
            maxCount = count;
        }
    }
    return answer;
}
