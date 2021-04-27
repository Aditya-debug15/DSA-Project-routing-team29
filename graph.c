#include<stdio.h>
#include<stdlib.h>

#include"graph.h"

PtrAdjList    CreateEmptyGraph(int degree)
{
    // A function to create an empty Adj List
    PtrAdjList G;
    G=(PtrAdjList)malloc(sizeof(AdjList));
    if(G==NULL)
    {
        printf("Memory full\n");
        exit(0);
    }
    G->degree=degree;
    G->vertex=(PtrNode)malloc(degree*sizeof(Node));
    if(G->vertex==NULL)
    {
        printf("Memory full\n");
        exit(0);  
    }
    // since array starts from 0 but our vertexid starts from 1 so vertexid becomes i+1
    for(int i=0;i<degree;i++)
    {
        G->vertex[i]->vertexid=i+1;
        G->vertex[i]->length=0;
        G->vertex[i]->cars=0;
        G->vertex[i]->time=0;
    }
    return G;
}