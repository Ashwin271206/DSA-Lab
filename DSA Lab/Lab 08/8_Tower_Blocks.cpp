// C++ Program to solve the tower blocks problem
#include <iostream>
#include <algorithm>
using namespace std;

int solve();

int main()
{
    int tests;
    cout << "Enter number of testcases : ";
    cin >> tests;
    if (tests == 0)
    {
        return 0;
    }
    int *output = (int *)malloc(tests * sizeof(int));
    for (int i = 0; i < tests; i++)
    {
        output[i] = solve();
    }
    cout << "\nOUTPUT : " << endl;
    for (int i = 0; i < tests; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}

// Function which finds maximum possible height of first tower
int solve()
{
    int towers;
    cout << "\nEnter number of towers : ";
    cin >> towers;
    if (towers == 0)
    {
        return 0;
    }
    int *arr = (int *)malloc(towers * sizeof(int));
    for (int i = 0; i < towers; i++)
    {
        cin >> arr[i];
    }
    int first = arr[0];
    sort(arr + 1, arr + towers);
    for (int i = 1; i < towers; i++)
    {
        if (arr[i] > first)
        {
            int extra = arr[i] - first;
            first += (extra + 1) / 2;
            arr[i] -= (extra + 1) / 2;
        }
    }
    return first;
}