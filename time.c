#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "time.h"

// this function stores the previous
// five time values from previous 5 inputs

timeHistoryTable *createEmptyTimeHistoryTable(int N)
{
    if (N <= 0)
    {
        return NULL;
    }

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

timeNode *makeTimeNode(double t1, double t2, double t3, double t4, double t5, int v)
{
    timeNode *tn = (timeNode *)malloc(sizeof(timeNode));
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

//a function to check if there is an edge from u to v
int isEdge(PtrAdjList G, int u, int v)
{
    PtrNode temp = G->vertex[u - 1].Next;

    while (temp->Next != NULL && temp->vertexid != v - 1)
    {
        temp = temp->Next;
    }

    if (temp->vertexid == v - 1)
        return 1;
    else
        return 0;
}

//from u to v
void addTimeNode(PtrAdjList G, timeHistoryTable *T, int u, double t1, double t2, double t3, double t4, double t5, int v)
{

    if (isEdge(G, u, v) == 1)
    {
        timeNode *tn = makeTimeNode(t1, t2, t3, t4, t5, v);

        tn->timeNext = T->tpointer[u - 1]->timeNext;
        T->tpointer[u - 1]->timeNext = tn;
    }
    else
    {
        printf("\nError: There is no edge from u to v\n");
    }
    return;
}

// function to print the time history table
void printTimeHistoryTable(timeHistoryTable* T)
{
    if (T == NULL)
    {
        printf("\nError: time history table does not exist\n");
        return;
    }
    for (int i = 0;i<T->no_of_vertices;i++)
    {
        timeNode* temp = T->tpointer[i]->timeNext;
        printf("%d", i+1);
        while(temp != NULL)
        {
            printf("=> %d ; %.2f,%.2f,%.2f,%.2f,%.2f",temp->vertexid,temp->time[0],temp->time[1],temp->time[2],temp->time[3],temp->time[4]);
            temp = temp->timeNext;
        }
        printf("=> NULL\n");
    }
    return;
}

