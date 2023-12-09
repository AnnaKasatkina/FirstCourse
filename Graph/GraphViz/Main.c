#include <stdio.h>
#include <stdlib.h>

#include "GraphViz.h"

int main(void) 
{
    int graph[SIZE][SIZE] = 
    {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
    };

    generateDotFile(graph);
    int result = system("dot -Tpng -o Graph.png Graph.dot");

    if (result == 0)
    {
        system("start Graph.png");
    }
    else
    {
        printf("Error!");
    }

    return 0;
}
