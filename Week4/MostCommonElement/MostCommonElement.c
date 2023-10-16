/*
Самый частый элемент
Переделать задачу про самый частый элемент в массиве из прошлого задания так,
чтобы сортировка была в отдельном модуле и читала входные данные из файла.
*/

#include "Sort.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void print(int* array, int length)
{
	for (int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n\n");
}

int mostCommonElement(int* array, int length)
{
	int count = 1;
	int max = 0;
	int answer = 0;
	for (int i = 1; i < length; ++i)
	{
		if (array[i] == array[i - 1])
		{
			count++;
		}
		else
		{
			if (count >= max)
			{
				answer = array[i - 1];
				max = count;
				count = 1;
			}
			count = 1;
		}
	}
	return answer;
}

int main(void)
{
	FILE* file = fopen("Array.txt", "r");

	int array[100] = { 0 };
	int length = 0;

	while (!feof(file)) 
	{
		const int readBytes = fscanf(file, "%d ", &array[length]);
		if (readBytes < 0) 
		{
			break;
		}
		++length;
	}
	fclose(file);

	insertionSort(array, 0, length - 1);

	printf("%d the most common element in the array: ", mostCommonElement(array, length));
	print(array, length);

	return 0;
}
