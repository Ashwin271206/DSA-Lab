// C++ Program to solve the 'Remove Prefix' problem
#include <iostream>
#include <vector>
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
    vector<int> output(tests);
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

// Function which finds the minimum number of elements that should be removed
int solve()
{
    int num;
    cout << "Enter length of sequence : ";
    cin >> num;
    vector<int> arr(num);
    vector<int> freq(num + 1, 0);
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < num; i++)
    {
        if (freq[arr[i]] > 1)
        {
            freq[arr[i]]--;
            ans = i + 1;
        }
    }
    return ans;
}