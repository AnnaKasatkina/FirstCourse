/*
�������� ��������� � ���������� ����������.
��� ������ ����� ������� ����� � ������ ���������,
� ������������� ������ ������������ ��������� ��������:

0 - �����
1 - �������� ������ (��� � �������)
2 - ����������� ��� ��������� ������
3 - ����� ������� �� �����
4 - ����� ��� �� ��������
5 - ��������� ������� ������ � ����

��� ������� ��������� ������ ������ ������ �� ����� (���� ������, � ������� ��������� ������),
���� ����� ��� � �������� � ������ ���� �������. ������ ���� ��������� ������ �������.
��������� �������� ��� �������� �������� ������� �� �������,
�������� ���� ������ ������ � ������ ���������, � ������������ � ������ �� ������� ������������.
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PhoneBook.h"

int print(size_t length, PhoneBookEntry *buffer)
{
    while (true)
    {
        printf("�������� ��������� ��������:\n"
            "0 - �����\n1 - �������� ������ (��� � �������)\n2 - ����������� ��� ��������� ������\n"
            "3 - ����� ������� �� �����\n4 - ����� ��� �� ��������\n5 - ��������� ������� ������ � ����\n��� �����: ");

        int choice = 0;

        if (scanf("%d", &choice) != 1)
        {
            return 1;
        }

        printf("\n");
        choose(choice, buffer, length);
        if (choice == 1)
        {
            length++;
        }
    }
    return 0;
}

size_t openFile(PhoneBookEntry* buffer)
{
    FILE* file = fopen("PhoneBook.txt", "a+");

    size_t length = 0;
    while (fscanf(file, "%s - %[^\n]", buffer[length].name, buffer[length].phone) == 2)
    {
        length++;
    }

    fclose(file);

    return length;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("����� ���������� � ���������� ����������!\n\n");


    PhoneBookEntry buffer[100] = { 0 };
    size_t length = openFile(buffer);

    if (print(length, buffer) != 0)
    {
        printf("������ �����!");
        return 1;
    }

    return 0;
}