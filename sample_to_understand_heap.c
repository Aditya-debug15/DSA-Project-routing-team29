#include<stdio.h>
#include<stdlib.h>
#include"graph.h"
#include"priority_queue.h"

int main()
{
    ptr_Minheap p=NULL;
    p = create_empty_heap(5);
    p->size = 5;
    p->position[0] = 0;
    p->position[1] = 1;
    p->position[2] = 2;
    p->position[3] = 3;
    p->position[4] = 4;
    p->Array[0].vertex = 1;
    p->Array[0].weight = 5;
    p->Array[1].vertex = 2;
    p->Array[1].weight = 7;
    p->Array[2].vertex = 3;
    p->Array[2].weight = 8;
    p->Array[3].vertex = 4;
    p->Array[3].weight = 9;
    p->Array[4].vertex = 5;
    p->Array[4].weight = 3;
    MinHeapify(p);
    ptr_node_for_heap n;
    n=ExtractMin(p);
    printf("%d %0.2f\n",n->vertex,n->weight);
    free(n);
    print_heap(p);
    DecreaseKey(p,2,2);
    n=ExtractMin(p);
    printf("%d %0.2f\n",n->vertex,n->weight);
    print_heap(p);
    printf("%d %d %d %d %d\n",p->position[0],p->position[1],p->position[2],p->position[3],p->position[4]);
    free(n);
    DeleteHeap(p);
}