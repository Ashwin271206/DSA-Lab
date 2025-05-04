#include <iostream>
#include <string>
#include "6_Stack_Linked_List.h"
using namespace std;

int check_balance(Stack);
int main()
{
    int choice;
    while (1)
    {
        string str;
        int len, result;
        cout << "\n\nMENU :\n 1. Check Balance\n 2. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        if (choice == 2)
        {
            cout << "Exiting Program." << endl;
            break;
        }
        else if (choice == 1)
        {
            Stack s1;
            cout << "Enter string to check balance : ";
            cin >> str;
            len = str.length();
            for (int i = 0; i < len; i++)
            {
                s1.push(str[i]);
            }
            result = check_balance(s1);
            if (result == 1)
            {
                cout << "Balanced String" << endl;
            }
            else if (result == 0)
            {
                cout << "Not balanced" << endl;
            }
            else
            {
                cout << "Invalid Input. Enter only a string of paranthesis." << endl;
            }
        }
        else
        {
            cout << "Invalid Choice." << endl;
        }
    }
}

int check_balance(Stack s)
{
    node *temp = s.gettop();
    int count = 0;

    while (temp != NULL)
    {
        if (temp->data == '(')
        {
            count--;
        }
        else if (temp->data == ')')
        {
            count++;
        }
        else
        {
            return -1;
        }
        if (count < 0)
        {
            return 0;
        }
        temp = temp->next;
    }
    if (count == 0)
    {
        return 1;
    }
    return 0;
}