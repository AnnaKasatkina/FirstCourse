#pragma once

#include <stdbool.h>

#define COUNT_NODES 6
#define COUNT_EDGES 4

typedef struct Graph
{
    struct Edge* edges[COUNT_EDGES];
} Graph;

Graph* makeGraph(const bool incidenceMatrices[COUNT_EDGES][COUNT_NODES]);

size_t** countComponents(const Graph* const graph);
