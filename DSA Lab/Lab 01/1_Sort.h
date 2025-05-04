#include <stdio.h>

void getInput(int arr[], int num)
{
    printf("Enter elements :\n");
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int num)
{
    for (int i = 0; i < num; ++i)
    {
        printf(" %d ", arr[i]);
    }
}

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