#include "Graph.h"

#include <stdlib.h>

typedef struct Edge
{
    size_t nodeOne;
    size_t nodeTwo;
} Edge;

size_t** countComponents(const Graph* const graph)
{
    size_t** components = (size_t**)calloc(COUNT_EDGES, sizeof(size_t*));
    if (components == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < COUNT_EDGES; i++)
    {
        components[i] = calloc(COUNT_NODES, sizeof(size_t));
        if (components == NULL)
        {
            return NULL;
        }
    }

    for (size_t i = 0; i < COUNT_EDGES; i++)
    {
        bool finded = false;
    }

    return components;
}

Graph* makeGraph(const bool incidenceMatrices[COUNT_EDGES][COUNT_NODES])
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < COUNT_EDGES; i++)
    {
        graph->edges[i] = (Edge*)calloc(1, sizeof(Edge));
        if (graph->edges[i] == NULL)
        {
            return NULL;
        }

        size_t count = 0;

        for (size_t j = 0; j < COUNT_NODES; j++)
        {
            if (incidenceMatrices[i][j] == 1)
            {
                if (count == 0)
                {
                    graph->edges[i]->nodeOne = j;
                    ++count;
                }
                else
                {
                    graph->edges[i]->nodeTwo = j;
                    ++count;
                }
            }
        }

        if (count != 2)
        {
            return NULL;
        }
    }

    return graph;
}
