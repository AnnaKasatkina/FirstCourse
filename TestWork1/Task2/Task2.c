#include <stdlib.h>

#include "Task2.h"

typedef struct
{
    int value;
    int priority;
} QueueNode;

typedef struct Node
{
    QueueNode data;
    struct Node* next;
} Node;

PriorityQueue* initializeQueue(void)
{
    PriorityQueue* queue = (PriorityQueue*)calloc(1, sizeof(PriorityQueue));

    return queue;
}

int isEmpty(PriorityQueue* queue)
{
    return (queue->front == NULL);
}

void enqueue(PriorityQueue* queue, int value, int priority, ErrorCode* errorCode)
{
    QueueNode newNodeData = { value, priority };
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        *errorCode = outOfMemory;
        return;
    }

    newNode->data = newNodeData;
    newNode->next = NULL;

    if (isEmpty(queue) || priority > queue->front->data.priority)
    {
        newNode->next = queue->front;
        queue->front = newNode;
    }
    else
    {
        Node* current = queue->front;
        while (current->next != NULL && priority <= current->next->data.priority) 
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    if (queue->rear == NULL)
    {
        queue->rear = newNode;
    }
}

int dequeue(PriorityQueue* queue, ErrorCode* errorCode)
{
    if (isEmpty(queue))
    {
        *errorCode = queueIsEmpty;
        return -1;
    }

    int result = queue->front->data.value;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    return result;
}

void freeQueue(PriorityQueue* queue)
{
    while (queue->front != NULL) 
    {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}
