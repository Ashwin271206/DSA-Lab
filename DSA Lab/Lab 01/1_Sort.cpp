#include <stdio.h>
#include <stdlib.h>

// Function to get array input from user
void getInput(int arr[], int num)
{
    printf("Enter elements :\n");
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", &arr[i]);
    }
}

// Function to display an array
void printArray(int arr[], int num)
{
    for (int i = 0; i < num; ++i)
    {
        printf(" %d ", arr[i]);
    }
}

// Selection Sort
void Selection(int arr[], int num)
{
    for (int i = 0; i < num - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < num; ++j)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// Bubble Sort
void Bubble(int arr[], int num)
{
    for (int i = 0; i < num - 1; ++i)
    {
        for (int j = 0; j < num - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
void Insertion(int arr[], int num)
{
    for (int i = 1; i < num; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int choice, num;
    int stop = 0;
    while (!stop)
    {
        printf("\nMenu :\n 1. Bubble Sort\n 2. Selection Sort\n 3. Insertion Sort\n 4. Exit\n"); // Printing Menu
        printf("Enter choice : ");                                                               // Getting choice from user
        scanf("%d", &choice);
        if (choice == 1 || choice == 2 || choice == 3)
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
        }
        int arr[num];
        switch (choice) // Implementing switch case
        {
        case 1:
            getInput(arr, num);
            Bubble(arr, num);
            printf("\n Sorted Array : \n");
            printArray(arr, num);
            break;

        case 2:
            getInput(arr, num);
            Selection(arr, num);
            printf("\n Sorted Array : \n");
            printArray(arr, num);
            break;

        case 3:
            getInput(arr, num);
            Insertion(arr, num);
            printf("\n Sorted Array : \n");
            printArray(arr, num);
            break;

        case 4:
            printf("\nCode Exitted Successfully."); // Exitting loop
            stop = 1;
            break;

        default:
            printf("Invalid Choice"); // Invalid choice for anything except 1,2,3,4
            break;
        }
    }

    return 0;
}