// C++ program to implement infix to postfix and postfix evaluation using stack ADT
#include <iostream>
#include "6_Evaluator.h"
using namespace std;

int main()
{
    int choice;
    do
    {
        cout << "\n\nMENU :\n 1. Get Infix\n 2. Convert Infix\n 3. Evaluate Postfix\n 4. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter a valid infix expression : ";
            getline(cin, infix);
            break;

        case 2:
            if (infix.empty())
            {
                cout << "No infix expression stored. Please enter an infix expression first.\n";
            }
            else
            {
                toPostfix(infix, postfix);
                cout << "Postfix Expression : " << postfix << endl;
            }
            break;

        case 3:
            if (postfix.empty())
            {
                cout << "No postfix expression generated. Convert infix to postfix first.\n";
            }
            else
            {
                double result = evaluate(postfix);
                cout << "Result = " << result << endl;
            }
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
}