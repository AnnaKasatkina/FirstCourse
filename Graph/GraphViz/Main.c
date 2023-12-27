#include <stdio.h>
#include <stdlib.h>

#include "GraphViz.h"

#define ERROR -1

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Usage: <input_file.dot> <output_file.png>\n");
        return ERROR;
    }

    int graph[SIZE][SIZE] = 
    {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
    };

    generateDotFile(argv[0], graph);

    char command[256] = {' '};
    snprintf(command, sizeof(command), "dot -Tpng -o %s %s", argv[0], argv[1]);
    int result = system(command);

    //if (result == 0)
    //{
    //    system("start Graph.png");
    //}
    //else
    //{
    //    printf("Error!");
    //}

    return 0;
}
