// C++ program to solve Nene's Game problem
#include <iostream>
#include <climits>
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
    int k, q;
    cin >> k >> q;
    int min_index = INT_MAX;
    int temp;
    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        if (temp < min_index)
        {
            min_index = temp;
        }
    }
    vector<int> num_players(q);
    for (int i = 0; i < q; i++)
    {
        cin >> num_players[i];
        if (num_players[i] >= min_index)
        {
            num_players[i] = min_index - 1;
        }
    }
    return num_players;
}