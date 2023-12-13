#include <stdio.h>
#include <stdlib.h>

#include "Task2.h"
#include "Tests.h"

#define ERROR -1
#define ERROR_STRING "Error!"

void printDequeue(PriorityQueue* const queue)
{
    ErrorCode errorCode = ok;
    int number = dequeue(queue, &errorCode);
    if (errorCode == queueIsEmpty)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued value: %d\n", number);
}

int main(void)
{
    if (!testResult())
    {
        printf("Error test!");
        return ERROR;
    }

    PriorityQueue* queue = initializeQueue();
    if (queue == NULL)
    {
        return ERROR;
    }

    ErrorCode errorCode = ok;
    enqueue(queue, 10, 7, &errorCode);
    if (errorCode != ok)
    {
        printf(ERROR_STRING);
        return ERROR;
    }
    enqueue(queue, 20, 3, &errorCode);
    if (errorCode != ok)
    {
        printf(ERROR_STRING);
        return ERROR;
    }
    enqueue(queue, 30, 10, &errorCode);
    if (errorCode != ok)
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    printDequeue(queue);
    printDequeue(queue);
    printDequeue(queue);

    printDequeue(queue);

    freeQueue(queue);

    return 0;
}
