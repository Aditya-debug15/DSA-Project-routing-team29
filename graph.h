#ifndef __GRAPH_H
#define __GRAPH_H

#define INF 1e5

typedef struct AdjList AdjList;
typedef struct AdjList* PtrAdjList;
typedef struct Node Node;
typedef struct Node* PtrNode;

struct AdjList{
    int degree;   // total number of vertex
    PtrNode vertex; // array of pointer to nodes
};

struct Node
{
    int vertexid; // number of the vertex
    double length;   // length of the road in km
    int cars;     // cars present on the road
    double time;   // time required to cross that road in minutes
    Node* Next;
};

// functions on the Adj List

PtrAdjList    CreateEmptyGraph(int degree);
void          InsertEdge(PtrAdjList G,int vertex1,int vertex2,double length,int cars);
void          UpdateDis(PtrAdjList G,int vertex1,int vertex2,double new_length);
void          UpdateCars(PtrAdjList G,int vertex1,int vertex2,int new_cars);
void          DeleteEdge(PtrAdjList G,int vertex1,int vertex2);
void          PrintList(PtrAdjList G);
void Dijkstra_shortest_length(PtrAdjList G,double* distance_source,int* prev,int source);
void Dijkstra_shortest_time(PtrAdjList G, double *time_source, int *prev, int source);
#endif