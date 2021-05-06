#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "priority_queue.h"
double CalTime(double length, int cars)
{
    double speed;
    double time;

    if(cars == 0)
    {
        speed = 60;
    }
    else if(cars > 0 && cars <= 80)
    {
        speed = 60 - (0.5)*cars;
    }
    else
    {
        speed = 20;
    }
    time = (length/speed)*60;
    return time;
}

PtrAdjList CreateEmptyGraph(int degree)
{
    // A function to create an empty Adj List
    PtrAdjList G;
    G = (PtrAdjList)malloc(sizeof(AdjList));
    if (G == NULL)
    {
        printf("Memory full\n");
        exit(0);
    }
    G->degree = degree;
    G->vertex = malloc(degree * sizeof(Node));
    if (G->vertex == NULL)
    {
        printf("Memory full\n");
        exit(0);
    }
    // since array starts from 0 but our vertexid starts from 1 so vertexid becomes i+1
    for (int i = 0; i < degree; i++)
    {
        G->vertex[i].vertexid = i + 1;
        G->vertex[i].length = 0;
        G->vertex[i].cars = 0;
        G->vertex[i].time = 0;
        G->vertex[i].Next = NULL;
    }
    return G;
}

void InsertEdge(PtrAdjList G, int vertex1, int vertex2, double length, int cars)
{
    // function to add an edge
    PtrNode temp = G->vertex[vertex1 - 1].Next;
    int checking;
    while (temp != NULL)
    {
        checking = temp->vertexid;
        if (checking == vertex2)
        {
            printf("Edge already exist\n");
            return;
        }
        temp = temp->Next;
    }
    PtrNode add = (PtrNode)malloc(sizeof(Node));
    PtrNode add2 = (PtrNode)malloc(sizeof(Node));
    if (add == NULL)
    {
        printf("Memory full\n");
        exit(0);
    }
    // inserting at the front if it is not present
    add->vertexid = vertex2;
    add->length = length;
    add->cars = cars;
    add->time = CalTime(length, cars);
    add->Next = G->vertex[vertex1 - 1].Next;
    G->vertex[vertex1 - 1].Next = add;
    add2->vertexid = vertex1;
    add2->length = length;
    add2->cars = cars;
    add2->time = add->time;
    add2->Next = G->vertex[vertex2 - 1].Next;
    G->vertex[vertex2 - 1].Next = add2;
}

void UpdateDis(PtrAdjList G, int vertex1, int vertex2, double new_length)
{
    PtrNode Temp_add = G->vertex[vertex1 - 1].Next;
    while (Temp_add != NULL && Temp_add->vertexid != vertex2)
    {
        Temp_add = Temp_add->Next;
    }
    if (Temp_add == NULL)
    {
        printf("Edge does not exist\n");
    }
    else
    {
        Temp_add->length = new_length;
    }
}

void          UpdateCars(PtrAdjList G,int vertex1,int vertex2,int new_cars)
{
    PtrNode temp = G->vertex[vertex1 - 1].Next;
   
    L1 :

    if (temp != NULL && temp->vertexid != vertex2)
    {
        temp = temp->Next;
        goto L1;
    }

    if(temp==NULL)
    {
          printf("Edge doesn't Exist\n");
    }

    else 
    {
        temp->cars = new_cars;
        printf("Sucessfully updated the number of cars\n");
    }
}

void PrintList(PtrAdjList G)
{
    // To print the Adj List
    int number = G->degree;
    for (int i = 0; i < number; i++)
    {
        PtrNode temp = G->vertex[i].Next;
        while (temp != NULL)
        {
            printf("vertex 1=%d and vertex 2 = %d\n", i + 1, temp->vertexid);
            printf("Distance between them is: %f and cars present are %d\n", temp->length, temp->cars);
            temp = temp->Next;
        }
        printf("\n");
    }
}

void Dijkstra_shortest_length(PtrAdjList G, double *distance_source, int *prev, int source)
{
    int *known;
    int n = G->degree;
    ptr_Minheap pq = create_empty_heap(n);
    pq->size = n;
    known = (int *)malloc((n + 1) * sizeof(int));
    known[source] = 0;
    distance_source[source] = 0;
    pq->position[source - 1] = 0;
    pq->Array[source - 1].vertex = source;
    pq->Array[source - 1].weight = 0;
    for (int i = 1; i <= n; i++)
    {
        prev[i]=-1;
        if (i!=source)
        {
            known[i] = 0;
            distance_source[i] = INF;
            pq->Array[i - 1].vertex = i;
            pq->Array[i - 1].weight = INF;
            pq->position[i - 1] = i - 1;
        }
    }
    MinHeapify(pq);
    while (pq->size > 0)
    {
        ptr_node_for_heap heap_node = ExtractMin(pq);
        known[heap_node->vertex] = 1;
        PtrNode temp = G->vertex[heap_node->vertex - 1].Next;
        // for all neighbours of u for whom SP is not known,
        // check if shorter path is available through u.
        while (temp != NULL)
        {
            int v = temp->vertexid;
            if ((!known[v]) && (distance_source[heap_node->vertex] + temp->length < distance_source[v]))
            {
                distance_source[v] = distance_source[heap_node->vertex] + temp->length; // Update dv
                prev[v]=heap_node->vertex;
                DecreaseKey(pq, v, distance_source[v]);
            }
            temp = temp->Next;
        }
    }
}
void print_shortest_path(int* prev,int source,int destination,Ptr_S Stack)
{
    Push(Stack,destination);
    while(prev[destination]!=source && source!=destination)
    {
        destination=prev[destination];
        Push(Stack,destination);
    }
    Push(Stack,source);
}
void Dijkstra_shortest_time(PtrAdjList G, double *time_source, int *prev, int source)
{
    int *known;
    int n = G->degree;
    ptr_Minheap pq = create_empty_heap(n);
    pq->size = n;
    known = (int *)malloc((n + 1) * sizeof(int));
    known[source] = 0;
    time_source[source] = 0;
    pq->position[source - 1] = 0;
    pq->Array[source - 1].vertex = source;
    pq->Array[source - 1].weight = 0;
    for (int i = 1; i <= n; i++)
    {
        prev[i]=-1;
        if (i!=source)
        {
            known[i] = 0;
            time_source[i] = INF;
            pq->Array[i - 1].vertex = i;
            pq->Array[i - 1].weight = INF;
            pq->position[i - 1] = i - 1;
        }
    }
    MinHeapify(pq);
    while (pq->size > 0)
    {
        ptr_node_for_heap heap_node = ExtractMin(pq);
        known[heap_node->vertex] = 1;
        PtrNode temp = G->vertex[heap_node->vertex - 1].Next;
        // for all neighbours of u for whom SP is not known,
        // check if shorter path is available through u.
        while (temp != NULL)
        {
            int v = temp->vertexid;
            if ((!known[v]) && (time_source[heap_node->vertex] + temp->time < time_source[v]))
            {
                time_source[v] = time_source[heap_node->vertex] + temp->time; // Update dv
                prev[v]=heap_node->vertex;
                DecreaseKey(pq, v, time_source[v]);
            }
            temp = temp->Next;
        }
    }
}
void print_shortes_time_path(int* prev,int source,int destination,Ptr_S Stack)
{
    Push(Stack,destination);
    while(prev[destination]!=source && source!=destination)
    {
        destination=prev[destination];
        Push(Stack,destination);
    }
    Push(Stack,source);
}