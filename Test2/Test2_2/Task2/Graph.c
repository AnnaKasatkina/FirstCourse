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
        for (size_t indexComponent = 0; indexComponent < COUNT_EDGES && !finded; indexComponent++)
        {
            for (size_t indexNode = 0; indexNode < COUNT_NODES && !finded; indexNode++)
            {
                if (components[indexComponent][indexNode] == graph->edges[i]->nodeOne)
                {
                    components[indexComponent][indexNode + 1] = graph->edges[i]->nodeTwo;
                    finded = true;
                }

                if (components[indexComponent][indexNode] == graph->edges[i]->nodeTwo)
                {
                    components[indexComponent][indexNode + 1] = graph->edges[i]->nodeOne;
                    finded = true;
                }
            }
        }
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
