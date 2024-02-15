#pragma once

#include "List.h"

// Добавление элемента в сортированный список
void addElement(List* const  list);

// Печать списка
void printList(const List* const list);

// Удаление элемента
void deleteElement(List* const list);

// Выбор функции по выбору пользователя
void choose(const size_t choice, List* const list);
