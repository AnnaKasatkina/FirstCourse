#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"

#define ERROR -1

int main(void)
{
    bool incidenceMatrices[COUNT_EDGES][COUNT_NODES] =
    { {1, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 1, 1, 0, 0} };

    Graph* graph = makeGraph(incidenceMatrices);
    if (graph == NULL)
    {
        printf("Error!");
        return ERROR;
    }
    countComponents(graph);

    return 0;
}