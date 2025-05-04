// C++ program to solve strength game problem
#include <iostream>
#include <vector>
using namespace std;

vector<int> solve();

int main()
{
    int tests;
    cin >> tests;
    if (tests == 0)
    {
        return 0;
    }
    vector<vector<int>> output(tests);
    for (int i = 0; i < tests; i++)
    {
        output[i] = solve();
    }
    cout << endl;
    for (int i = 0; i < tests; i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}

// Function to solve and return output vector
// Time complexity = O(n)
vector<int> solve()
{
    int num;
    cin >> num;
    vector<int> strengths(num);
    int max = 0, max2 = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> strengths[i];
        if (strengths[i] > max)
        {
            max2 = max;
            max = strengths[i];
        }
        else if (strengths[i] > max2)
        {
            max2 = strengths[i];
        }
    }
    for (int i = 0; i < num; i++)
    {
        if (strengths[i] == max)
        {
            strengths[i] -= max2;
        }
        else
        {
            strengths[i] -= max;
        }
    }
    return strengths;
}