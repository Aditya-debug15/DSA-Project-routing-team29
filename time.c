#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// this function stores the previous
// five time values from previous 5 inputs

// the input taken should be like
// feed us yhe previous 5 days data
// for each edge

// the user will give five situations for
// each edge. If he wants to give same
// data as privious day then he should have
// the option as well

#define DONTCARE 0

typedef struct timeNode timeNode;
typedef struct timeHistoryTable timeHistoryTable;

struct timeHistoryTable
{
    int no_of_vertices;
    timeNode **tpointer;
};

// int no_of_vertices is added to avoid using G
// as a input (G->vertex)

struct timeNode
{
    int vertexid;
    double time[5];
    timeNode *timeNext;
};

timeHistoryTable *createEmptyTimeHistoryTable(int N)
{
    timeHistoryTable *T = (timeHistoryTable *)malloc(sizeof(timeHistoryTable));
    assert(T != NULL);

    T->no_of_vertices = N;
    T->tpointer = (timeNode **)malloc(N * sizeof(timeNode *));
    assert(T->tpointer != NULL);

    for (int i = 0; i < N; i++)
    {
        T->tpointer[i] = (timeNode *)malloc(sizeof(timeNode));
        assert(T->tpointer[i] != NULL);

        T->tpointer[i]->vertexid = i + 1;
        T->tpointer[i]->timeNext = NULL;

        for (int j = 0; j < 5; j++)
            T->tpointer[i]->time[j] = DONTCARE;
    }

    return T;
}

timeNode* makeTimeNode(double t1, double t2, double t3, double t4, double t5, int v)
{
    timeNode* tn = (timeNode*)malloc(sizeof(timeNode));
    assert(tn != NULL);

    tn->vertexid = v;
    tn->time[0] = t1;
    tn->time[1] = t2;
    tn->time[2] = t3;
    tn->time[3] = t4;
    tn->time[4] = t5;
    tn->timeNext = NULL;

    return tn;
}

//from u to v
void addTimeNode(timeHistoryTable* T, int u, double t1, double t2, double t3, double t4, double t5, int v)
{
    timeNode* tn = makeTimeNode(t1,t2,t3,t4,t5,v);

    tn->timeNext = T->tpointer[u-1]->timeNext;
    T->tpointer[u-1]->timeNext = tn;

    return;
}

// in main.c file it would look something like
// enter data for this edge for previous days:
// 5 times scanf in a while loop(loop traverses through edges)
// take time from each entry and then use this functions 
// to store the data
