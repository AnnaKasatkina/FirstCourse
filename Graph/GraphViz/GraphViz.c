#include "GraphViz.h"

#include <stdio.h>

void generateDotFile(const char* const nameFile, const int graph[SIZE][SIZE])
{
    FILE* dotFile = fopen(nameFile, "w");
    if (dotFile == NULL)
    {
        perror("Error opening .dot file");
        return;
    }

    fprintf(dotFile, "graph G {\n");

    fprintf(dotFile, "node [shape=circle];\n"
        "node [fontname=\"Helvetica\", fontsize=20];\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = i; j < SIZE; j++) {
            if (graph[i][j] == 1) {
                fprintf(dotFile, "  %d -- %d;\n", i + 1, j + 1);
            }
        }
    }

    fprintf(dotFile, "}\n");

    fclose(dotFile);
}
