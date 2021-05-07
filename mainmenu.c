#include <stdio.h>
#include "graph.h"
int main()
{
    int choice, i, n;

MENU:
    printf("To create a graph, press 1\n");
    printf("To enter number of nodes, press 2\n");
    printf("To add an edge, press 3\n");
    printf("To update distance, press 4\n");
    printf("To update number of cars, press 5\n");
    printf("To find shortest distance, press 6\n");
    printf("To find least time, press 7\n");
    printf("To find a safe distance, press 8\n");
    printf("To exit the program, press 9\n\n");
    scanf("%d", &choice);
    if (choice < 1 || choice > 9)
    {
        printf("\nInvalid command\n5");
        goto MENU;
    }

    if (choice == 1)
    {
        printf("You have selected to create a graph \nTo continue press 1, To go back to main MENU press 0\n");
        scanf("%d", &n);
        if (n == 1)
        {
            PtrAdjList g = CreateEmptyGraph(int degree);
        }
        if (n == 0)
        {
            goto MENU;
        }
    }

    if (choice == 2)
    {
        printf("You have selected to enter the number of nodes \nTo continue press 1, To go back to main MENU press 0\n");
        scanf("%d", &n);
        if (n == 1)
        {
            goto check;
        }
        if (n == 0)
        {
            goto MENU;
        }
    }
    if (choice == 3)
    {
        printf("You have selected to add an edge \nTo continue press 1, To go back to main MENU press 0\n");
        scanf("%d", &n);
        if (n == 1)
        {
            InsertEdge(PtrAdjList G, int vertex1, int vertex2, double length, int cars);
        }
        if (n == 0)
        {
            goto MENU;
        }
    }
    if (choice == 4)
    {
        printf("You have selected to update distance \nTo continue press 1, To go back to main MENU press 0\n");
        scanf("%d", &n);
        if (n == 1)
        {
            UpdateDis(PtrAdjList G, int vertex1, int vertex2, double new_length);
        }
        if (n == 0)
        {
            goto MENU;
        }
    }
    if (choice == 5)
    {
        printf("You have selected to update number of cars \nTo continue press 1, To go back to main MENU press 0\n");
        scanf("%d", &n);
        if (n == 1)
        {
            UpdateCars(PtrAdjList G, int vertex1, int vertex2, int new_cars);
        }
        if (n == 0)
        {
            goto MENU;
        }
    }
    if (choice == 6)
    {
        printf("You have selected to find shortest distance \nTo continue press 1, To go back to main MENU press 0\n");
        scanf("%d", &n);
        if (n == 1)
        {
            goto check;
        }
        if (n == 0)
        {
            goto MENU;
        }
    }
    if (choice == 7)
    {
        printf("You have selected to find least time \nTo continue press 1, To go back to main MENU press 0\n");
        scanf("%d", &n);
        if (n == 1)
        {
            Dijkstra_shortest_time(PtrAdjList G, double *time_source, int *prev, int source)
        }
        if (n == 0)
        {
            goto MENU;
        }
    }
    if (choice == 8)
    {
        printf("You have selected to find a safe distance \nTo continue press 1, To go back to main MENU press 0\n");
        scanf("%d", &n);
        if (n == 1)
        {
            print_shortes_time_path(int *prev, int source, int destination, Ptr_S Stack)
        }
        if (n == 0)
        {
            goto MENU;
        }
    }
    if (choice == 9)
    {
        printf("You have selected to exit the program \nTo continue press 1, To stay in the main MENU press 0\n");
        scanf("%d", &n);
        if (n == 1)
        {
            goto check;
        }
        if (n == 0)
        {
            goto MENU;
        }
    }

    return 0;
}