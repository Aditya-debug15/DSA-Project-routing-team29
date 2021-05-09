#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "priority_queue.h"
#include "time.h"

int main()
{
    int choice, repeat, n, degree;
    PtrAdjList G;
    PtrAdjList graph;
    timeHistoryTable *T;

    printf("WELCOME!\n ROUTING\n");
    printf("(Mini Project - Group 29 under TA Mr. Tanish Lad\n)");
    printf("By Aditya Malhotra(2020101052)\tParshva Bhadra(2020101001)\tAnubhav Pal(2020112012)\tKarnati Jahnavi(2020102052)\tAaryan Sharma(2020115008)");

    printf("Please enter the total number of vertices: \n");
    scanf("%d", &degree);

    G = CreateEmptyGraph(degree);
    T = createEmptyTimeHistoryTable(degree);

MENU:
    printf("\n");
    printf("To add an edge, press 1\n");
    printf("To delete an edge, press 2\n");
    printf("To update distance, press 3\n");
    printf("To update number of cars, press 4\n");
    printf("To find shortest distance, press 5\n");
    printf("To find least time, press 6\n");
    printf("To find a safe path, press 7\n");
    printf("To exit the program, press 8\n\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > 9)
    {
        printf("\nInvalid command!\n");
        goto MENU;
    }

    if (choice == 1)
    {

        printf("\nYou have selected to add an edge.\n");
        printf("To continue, Press 1\nTo go back to the main menu, Press 0\n");

    POINT1:
        scanf("%d", &n);
        if (n == 1)
        {
            int vertex1, vertex2, cars;
            double length;

        POINT11:
            printf("\nEnter the vertices between which you want to insert an edge: \n");
            scanf("%d%d", &vertex1, &vertex2);
            printf("Enter the length of the edge: \n");
            scanf("%lf", &length);
            printf("Enter the number of cars on the edge: \n");
            scanf("%d", &cars);
            InsertEdge(G, vertex1, vertex2, length, cars);

            printf("Successfully added an edge. \n");
            printf("Do you want to add another edge?\n");
            printf("If YES, Press 1 \nIf No, Press 0\n");

        POINT12:
            scanf("%d", &repeat);
            if (repeat == 1)
            {
                goto POINT11;
            }
            if (repeat == 0)
            {
                goto MENU;
            }
            if (repeat != 1 || repeat != 0)
            {
                printf("Invalid Command! Please Enter again.\n");
                goto POINT12;
            }
        }

        if (n == 0)
        {
            goto MENU;
        }

        if (n != 0 || n != 1)
        {
            printf("Invalid Command. Please Enter again.\n");
            goto POINT1;
        }
    }

    if (choice == 2)
    {

        printf("\nYou have selected to delete an edge\n");
        printf("To continue, Press 1\nTo go back to the main menu, Press 0\n");

    POINT2:
        scanf("%d", &n);
        if (n == 1)
        {
            int vertex1, vertex2;

        POINT21:
            printf("Enter the vertices between which you want to delete the edge");
            scanf("%d%d", &vertex1, &vertex2);
            DeleteEdge(G, vertex1, vertex2);

            printf("Successfully deleted the desired edge. \n");
            printf("Do you want to delete another edge?\n");
            printf("If YES, Press 1 \nIf No, Press 0\n");

        POINT22:
            scanf("%d", &repeat);
            if (repeat == 1)
            {
                goto POINT21;
            }
            if (repeat == 0)
            {
                goto MENU;
            }
            if (repeat != 1 || repeat != 0)
            {
                printf("Invalid Command! Please Enter again.\n");
                goto POINT22;
            }
        }

        if (n == 0)
        {
            goto MENU;
        }

        if (n != 0 || n != 1)
        {
            printf("Invalid Command. Please Enter again.\n");
            goto POINT2;
        }
    }

    if (choice == 3)
    {
        printf("You have selected to update distance \n");
        printf("To continue, Press 1\nTo go back to the main menu, Press 0\n");

    POINT3:

        scanf("%d", &n);
        if (n == 1)
        {
            int vertex1, vertex2;
            double new_length;

        POINT31:
            printf("Enter the vertices between which you want to update distance\n");
            scanf("%d%d", &vertex1, &vertex2);
            printf("Enter the new distance\n");
            scanf("%lf", &new_length);
            UpdateDis(G, vertex1, vertex2, new_length);

            printf("Successfully updated the distance. \n");
            printf("Do you want to update another distance?\n");
            printf("If YES, Press 1 \nIf No, Press 0\n");

        POINT32:
            scanf("%d", &repeat);
            if (repeat == 1)
            {
                goto POINT31;
            }
            if (repeat == 0)
            {
                goto MENU;
            }
            if (repeat != 1 || repeat != 0)
            {
                printf("Invalid Command! Please Enter again.\n");
                goto POINT32;
            }
        }

        if (n == 0)
        {
            goto MENU;
        }

        if (n != 0 || n != 1)
        {
            printf("Invalid Command. Please Enter again.\n");
            goto POINT3;
        }
    }

    if (choice == 4)
    {
        printf("You have selected to update number of cars \n");
        printf("To continue, Press 1\nTo go back to the main menu, Press 0\n");

    POINT4:
        scanf("%d", &n);
        if (n == 1)
        {
            int vertex1, vertex2;
            int new_cars;

        POINT41:
            printf("Enter the vertices between which you want to update number of cars\n");
            scanf("%d%d", &vertex1, &vertex2);
            printf("Enter the updated number of cars\n");
            scanf("%d", &new_cars);
            UpdateCars(G, vertex1, vertex2, new_cars);

            printf("Successfully updated the number of cars. \n");
            printf("Do you want to update another number of cars?\n");
            printf("If YES, Press 1 \nIf No, Press 0\n");

        POINT42:
            scanf("%d", &repeat);
            if (repeat == 1)
            {
                goto POINT41;
            }
            if (repeat == 0)
            {
                goto MENU;
            }
            if (repeat != 1 || repeat != 0)
            {
                printf("Invalid Command! Please Enter again.\n");
                goto POINT42;
            }
        }
        if (n == 0)
        {
            goto MENU;
        }
        if (n != 0 || n != 1)
        {
            printf("Invalid Command. Please Enter again.\n");
            goto POINT4;
        }
    }

    if (choice == 5)
    {

        printf("You have selected to find shortest distance \n");
        printf("To continue, Press 1,\nTo go back to the main menu, Press 0\n");

    POINT5:
        scanf("%d", &n);
        if (n == 1)
        {
            int source, destination;

        POINT51:
            printf("Enter the source of the path: \n");
            scanf("%d", &source);
            printf("Enter the destination of the path: \n");
            scanf("%d", &destination);
            shortest_distance_choice4(graph, source, destination);

            printf("Successfully found the shortest distance. \n");
            printf("Do you want to find shortest distance between another source and destination?\n");
            printf("If YES, Press 1 \nIf No, Press 0\n");

        POINT52:
            scanf("%d", &repeat);
            if (repeat == 1)
            {
                goto POINT51;
            }
            if (repeat == 0)
            {
                goto MENU;
            }
            if (repeat != 1 || repeat != 0)
            {
                printf("Invalid Command! Please Enter again.\n");
                goto POINT52;
            }
        }

        if (n == 0)
        {
            goto MENU;
        }

        if (n != 0 || n != 1)
        {
            printf("Invalid Command. Please Enter again.\n");
            goto POINT5;
        }
    }

    if (choice == 6)
    {

        printf("You have selected to find least time \n");
        printf("To continue, Press 1,\nTo go back to the main menu, Press 0\n");

    POINT6:
        scanf("%d", &n);
        if (n == 1)
        {
            int source, destination;

        POINT61:
            printf("Please enter the source of path");
            scanf("%d", &source);
            printf("Please enter the destination of the path");
            scanf("%d", &destination);
            shortest_time_choice5(graph, source, destination);
            printf("Successfully found the least time! \n");
            printf("Do you want to find least time between another source and destination?\n");
            printf("If YES, Press 1 \nIf No, Press 0\n");

        POINT62:
            scanf("%d", &repeat);
            if (repeat == 1)
            {
                goto POINT61;
            }
            if (repeat == 0)
            {
                goto MENU;
            }
            if (repeat != 1 || repeat != 0)
            {
                printf("Invalid Command! Please Enter again.\n");
                goto POINT62;
            }
        }

        if (n == 0)
        {
            goto MENU;
        }

        if (n != 0 || n != 1)
        {
            printf("Invalid Command. Please Enter again.\n");
            goto POINT6;
        }
    }

    if (choice == 7)
    {

        printf("You have selected to find a safe distance \n");
        printf("To continue, Press 1,\nTo go back to the main menu, Press 0\n");

    POINT7:
        scanf("%d", &n);
        if (n == 1)
        {
            int source, destination;

        POINT71:
            printf("Please enter the source of path");
            scanf("%d", &source);
            printf("Please enter the destination of the path");
            scanf("%d", &destination);
            SafeAlgorithmStart(T, G, source, destination);
            printf("Successfully found the safest path. \n");
            printf("Do you want to find safest path between another source and destination?\n");
            printf("If YES, Press 1 \nIf No, Press 0\n");

        POINT72:
            scanf("%d", &repeat);
            if (repeat == 1)
            {
                goto POINT71;
            }
            if (repeat == 0)
            {
                goto MENU;
            }
            if (repeat != 1 || repeat != 0)
            {
                printf("Invalid Command! Please Enter again.\n");
                goto POINT72;
            }
        }

        if (n == 0)
        {
            goto MENU;
        }

        if (n != 0 || n != 1)
        {
            printf("Invalid Command. Please Enter again.\n");
            goto POINT7;
        }
    }

    if (choice == 8)
    {

        printf("You have selected to exit the program \n");
        printf("To continue, Press 1,\nTo stay in the main menu, Press 0\n");

    POINT8:
        scanf("%d", &n);
        if (n == 1)
        {
            DeleteList(G);
            //parshav T//
            printf("Thank You, Have a nice day");
        }
        if (n == 0)
        {
            goto MENU;
        }
        if (n != 0 || n != 1)
        {
            printf("Invalid Command. Please Enter again.\n");
            goto POINT8;
        }
    }

    return 0;
}