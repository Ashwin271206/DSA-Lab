// C++ program to contruct an Expression Tree using functions of the header file
#include <iostream>
#include <string.h>
#include "9_Expression_Tree.h"
using namespace std;

int main()
{
    int choice;
    Tree tree;
    string input;
    while (true)
    {
        cout << "\n\nMENU :\n 1. Get Postfix\n 2. Construct Tree\n 3. Display Prefix" << endl;
        cout << "4. Display Infix\n 5. Display Postfix\n 6. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;

        if (choice == 6)
        {
            cout << "Exitting code." << endl;
            break;
        }
        else if (choice > 6 || choice < 1)
        {
            cout << "Invalid choice. Enter again." << endl;
        }
        else if (choice == 1)
        {
            cout << "Enter a valid postfix expression : ";
            cin >> input;
        }
        else
        {
            if (input.empty())
            {
                cout << "No expression entered. Please enter a valid postifx expression to proceed." << endl;
            }
            else
            {
                switch (choice)
                {
                case 2:
                    tree.constructTree(input);
                    cout << "Tree constructed." << endl;
                    break;

                case 3:
                    tree.preorder(tree.getRoot());
                    break;

                case 4:
                    tree.inorder(tree.getRoot());
                    break;

                case 5:
                    tree.postorder(tree.getRoot());
                    break;
                }
            }
        }
    }
}