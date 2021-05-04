#include<stdio.h>
#include<stdlib.h>

#include"graph.h"
double CalTime(double length,int cars)
{
    // This is an incorrect function just made it to test my program
    return 1;
}

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
    G->vertex=malloc(degree*sizeof(Node));
    if(G->vertex==NULL)
    {
        printf("Memory full\n");
        exit(0);  
    }
    // since array starts from 0 but our vertexid starts from 1 so vertexid becomes i+1
    for(int i=0;i<degree;i++)
    {
        G->vertex[i].vertexid=i+1;
        G->vertex[i].length=0;
        G->vertex[i].cars=0;
        G->vertex[i].time=0;
        G->vertex[i].Next=NULL;
    }
    return G;
}

void          InsertEdge(PtrAdjList G,int vertex1,int vertex2,double length,int cars)
{
    // function to add an edge
    PtrNode temp=G->vertex[vertex1-1].Next;
    int checking;
    while(temp!=NULL)
    {
        checking=temp->vertexid;
        if(checking==vertex2)
        {
            printf("Edge already exist\n");
            return;
        }
        temp=temp->Next;
    }
    PtrNode add=(PtrNode)malloc(sizeof(Node));
    PtrNode add2=(PtrNode)malloc(sizeof(Node));
    if(add==NULL)
    {
        printf("Memory full\n");
        exit(0);
    }
    // inserting at the front if it is not present
    add->vertexid=vertex2;
    add->length=length;
    add->cars=cars;
    add->time=CalTime(length,cars);
    add->Next=G->vertex[vertex1-1].Next;
    G->vertex[vertex1-1].Next=add;
    add2->vertexid=vertex1;
    add2->length=length;
    add2->cars=cars;
    add2->time=add->time;
    add2->Next=G->vertex[vertex2-1].Next;
    G->vertex[vertex2-1].Next=add2;
}

void          UpdateDis(PtrAdjList G,int vertex1,int vertex2,double new_length)
{
    PtrNode Temp_add=G->vertex[vertex1-1].Next;
    while(Temp_add!=NULL && Temp_add->vertexid!=vertex2)
    {
        Temp_add=Temp_add->Next;
    }
    if(Temp_add==NULL)
    {
        printf("Edge does not exist\n");
    }
    else{
        Temp_add->length=new_length;
    }
}

void          PrintList(PtrAdjList G)
{
    // To print the Adj List
    int number=G->degree;
    for(int i=0;i<number;i++)
    {
        PtrNode temp=G->vertex[i].Next;
        while(temp!=NULL)
        {
            printf("vertex 1=%d and vertex 2 = %d\n",i+1,temp->vertexid);
            printf("Distance between them is: %f and cars present are %d\n",temp->length,temp->cars);
            temp=temp->Next;
        }
        printf("\n");
    }
}
