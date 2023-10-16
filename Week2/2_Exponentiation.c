/*
Возведение в степень
Реализовать возведение в целую степень — в лоб
(за линейное время) и за О(log n).
*/

#include <stdio.h>

int linearTime(int number, int degree)
{
    int intermediate = 1;
    for (int i = 1; i <= degree; i++)
    {
        intermediate = intermediate * number;
    }
    return intermediate;
}

int logarithmTime(int number, int degree)
{
    if (degree == 0)
    {
        return 1;
    }
    else if (degree % 2 == 0)
    {
        int intermediate = logarithmTime(number, degree / 2);
        return intermediate * intermediate;
    }
    else
    {
        return logarithmTime(number, degree - 1) * number;
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter your number and degree: ");

    int number = 0;
    int degree = 0;
    scanf("%d %d", &number, &degree);

    printf("Result = %d\n", linearTime(number, degree));
    printf("Result = %d", logarithmTime(number, degree));

    return 0;
}