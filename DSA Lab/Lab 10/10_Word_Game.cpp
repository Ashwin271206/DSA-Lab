// C++ program to solve word game problem
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> solve();

int main()
{
    int tests;
    cout << "Enter number of testcases : ";
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
    cout << "OUTPUT : " << endl;
    for (int i = 0; i < tests; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << output[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}

// Function to solve and return scores
vector<int> solve()
{
    int num;
    cout << "Enter number of words : ";
    cin >> num;
    string inp;
    vector<vector<string>> words(3, vector<string>(num));
    unordered_map<string, int> wordcount;
    for (int i = 0; i < 3; i++)
    {
        cout << "Player " << i + 1 << " : " << endl;
        for (int j = 0; j < num; j++)
        {
            cin >> inp;
            words[i][j] = inp;
            wordcount[inp]++;
        }
    }
    vector<int> scores(3, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < num; j++)
        {
            inp = words[i][j];
            if (wordcount[inp] == 1)
            {
                scores[i] += 3;
            }
            else if (wordcount[inp] == 2)
            {
                scores[i] += 1;
            }
        }
    }
    return scores;
}