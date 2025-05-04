#include <stdio.h>
#include <stdlib.h>

int length(int *num);
int reverse(int *num);
int power(int *num, int *pow);
void palindrome(int *num);
void armstrong(int *num);
void perfect(int *num);

int main()
{
    int *num = (int *)malloc(sizeof(int));
    int *choice = (int *)malloc(sizeof(int));
    int *stop = (int *)calloc(1, sizeof(int));

    while (!(*stop))
    {
        printf("\n\nMENU :");
        printf("\n 1. To check whether a number is a palindrome");
        printf("\n 2. To check whether a number is an Armstrong number");
        printf("\n 3. To check whether a number is a Perfect number");
        printf("\n 4. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", choice);

        if (*choice == 1 || *choice == 2 || *choice == 3)
        {
            while (1)
            {
                printf("Enter number to check : ");
                scanf("%d", num);
                if (*num > 0)
                {
                    break;
                }
                else
                {
                    printf("Invalid input. Enter only positive numbers.\n\n");
                }
            }
        }

        switch (*choice)
        {
        case 1:
            palindrome(num);
            break;
        case 2:
            armstrong(num);
            break;
        case 3:
            perfect(num);
            break;
        case 4:
            printf("Exitting Program.");
            *stop = 1;
            break;
        default:
            printf("Invalid Choice.");
            break;
        }
    }
}

int length(int *num)
{
    int *digit = (int *)calloc(1, sizeof(int));
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;
    while (*temp > 0)
    {
        (*digit)++;
        *temp /= 10;
    }
    free(temp);
    return *digit;
}

int reverse(int *num)
{
    int *rev = (int *)calloc(1, sizeof(int));
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;
    for (int *i = (int *)calloc(1, sizeof(int)); *i < length(num); (*i)++)
    {
        *rev = *rev * 10 + (*temp % 10);
        *temp /= 10;
    }
    free(temp);
    return *rev;
}

int power(int *num, int *exp)
{
    int *pow = (int *)malloc(sizeof(int));
    *pow = 1;

    for (int *i = (int *)calloc(1, sizeof(int)); *i < *exp; (*i)++)
    {
        *pow *= *num;
    }

    return *pow;
}

void palindrome(int *num)
{
    if (reverse(num) == *num)
    {
        printf("%d is a palindrome.", *num);
    }
    else
    {
        printf("%d is NOT a palindrome.", *num);
    }
}

void armstrong(int *num)
{
    int *sum = (int *)calloc(1, sizeof(int));
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;
    int *len = (int *)malloc(sizeof(int));
    *len = length(num);

    while (*temp)
    {
        int *digit = (int *)malloc(sizeof(int));
        *digit = *temp % 10;
        *sum += power(digit, len);
        *temp /= 10;
        free(digit);
    }
    free(len);
    if (*num == *sum)
    {
        printf("%d is an Armstrong number.", *num);
    }
    else
    {
        printf("%d is NOT an Armstrong number.", *num);
    }
    free(temp);
    free(sum);
}

void perfect(int *num)
{
    int *sum = (int *)calloc(1, sizeof(int));
    for (int *i = (int *)calloc(1, sizeof(int)); *i <= (*num) / 2; (*i)++)
    {
        if ((*i) != 0)
        {
            if ((*num % *i) == 0)
            {
                *sum += *i;
            }
        }
    }
    if (*num == *sum)
    {
        printf("%d is a Perfect number.", *num);
    }
    else
    {
        printf("%d is NOT a Perfect number.", *num);
    }
    free(sum);
}