#pragma once

#include <stdlib.h>

typedef struct Node Node;

typedef struct
{
    Node* front;
    Node* rear;
} PriorityQueue;

typedef enum
{
    ok,
    outOfMemory,
    queueIsEmpty
} ErrorCode;

PriorityQueue* initializeQueue(void);

void enqueue(PriorityQueue* queue, int value, int priority, ErrorCode* errorCode);

int dequeue(PriorityQueue* queue, ErrorCode* errorCode);

void freeQueue(PriorityQueue* queue);
