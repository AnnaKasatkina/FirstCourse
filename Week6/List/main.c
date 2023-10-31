#include "List.h"
#include "CyclicList.h"

#define ERROR -1

int main() 
{
    printf("Enter the number of wars and kill rate: ");
    int gap = 0;
    int amount = 0;

    if (scanf("%d %d", &amount, &gap) != 2) {
        printf("Input Error");
        return ERROR;
    }

    List* list = 0;
    initList(&list);

    fillList(amount, list);
    count(amount, gap, list);
    printResult(list);

    return 0;
}
