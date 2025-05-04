#include <stdio.h>
#include <stdlib.h>
#include "1_Sort.h"

// Linear Search function
void Linear(int arr[], int num, int target)
{
    int found = 0;
    for (int i = 0; i < num; ++i)
    {
        if (arr[i] == target)
        {
            printf("Element found at index %d.", i);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Element not found");
    }
}

// Binary Search function
void Binary(int arr[], int num, int target)
{
    Bubble(arr, num);
    int found = 0, left = 0, right = num - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] == target)
        {
            printf("Element found at index %d in sorted array.\n", middle);
            found = 1;
            break;
        }
        if (arr[middle] < target)
        {
            left = middle + 1;
        }
        if (arr[middle] > target)
        {
            right = middle - 1;
        }
    }
    if (found == 0)
    {
        printf("Element not found\n");
    }
}

int main()
{
    int num, target, choice;
    int *arr = NULL;
    int stop = 0;
    while (!stop)
    {
        printf("\nMenu :\n 1. Linear Search \n 2. Binary Serach\n 3. Exit\n"); // Printing Menu
        printf("Enter choice : ");                                             // Getting choice from user
        scanf("%d", &choice);
        if (choice == 1 || choice == 2)
        {
            int valid = 0;
            while (!valid)
            {
                printf("\nEnter the size of the array : ");
                scanf("%d", &num);
                if (num <= 0) // Checking for positive non zero value of size
                {
                    printf("Invalid Size.");
                }
                else
                {
                    valid = 1;
                }
            }
            arr = (int *)malloc(num * sizeof(int));
            getInput(arr, num);
            printf("Enter element to search for : ");
            scanf("%d", &target);
        }
        switch (choice)
        {
        case 1:
            Linear(arr, num, target);
            printf("\nSearched using Linear Search.\n");
            break;

        case 2:
            Binary(arr, num, target);
            printf("\nSearched using Binary Search.\n");
            break;

        case 3:
            stop = 1;
            printf("Exitted Successfully."); // Exitting loop
            break;

        default:
            printf("Invalid Choice"); // Invalid choice for anything except 1,2,3
            break;
        }
        free(arr);
    }
    return 0;
}