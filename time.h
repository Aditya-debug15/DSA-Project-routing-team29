#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DONTCARE 0

typedef struct timeNode timeNode;
typedef struct timeHistoryTable timeHistoryTable;

struct timeHistoryTable
{
    int no_of_vertices;
    timeNode **tpointer;
};

struct timeNode
{
    int vertexid;
    double time[5];
    timeNode *timeNext;
};

timeHistoryTable *createEmptyTimeHistoryTable(int N);
timeNode* makeTimeNode(double t1, double t2, double t3, double t4, double t5, int v);
void addTimeNode(timeHistoryTable* T, int u, double t1, double t2, double t3, double t4, double t5, int v); // u to v
