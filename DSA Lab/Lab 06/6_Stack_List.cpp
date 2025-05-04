// C++ program to perform stack implementation using list
#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    char arr[5];

public:
    Stack();
    bool push(char);
    char pop();
    char peek();
};

int main()
{
    int choice, stop = 0;
    char val;
    Stack s1;
    while (!stop)
    {
        cout << "\n\nMENU :\n 1. Push\n 2. Pop\n 3. Peek\n 4. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push : ";
            cin >> val;
            if (s1.push(val) == 0)
            {
                cout << "Stack Overflow. Push failed." << endl;
            }
            else
            {
                cout << "Push Successful." << endl;
            }
            break;

        case 2:
            val = s1.pop();
            if (val == '\0')
            {
                cout << "Empty Stack. Pop failed." << endl;
            }
            else
            {
                cout << "Pop successful. Popped element : " << val << endl;
            }
            break;

        case 3:
            val = s1.peek();
            if (val == '\0')
            {
                cout << "Empty Stack." << endl;
            }
            else
            {
                cout << "Top --> " << val << endl;
            }
            break;

        case 4:
            stop = 1;
            cout << "Exitting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    }
}

// Constructor function to initialize top
Stack::Stack()
{
    top = -1;
}

// Function to push an element into the stack
bool Stack::push(char val)
{
    if (top == 4)
    {
        cout << "\nStack Overflow." << endl;
        return 0;
    }
    top++;
    arr[top] = val;
    return 1;
}

// Function to pop the top element out of the stack
char Stack::pop()
{
    if (top == -1)
    {
        return '\0';
    }
    char temp = arr[top];
    top--;
    return temp;
}

// Function to peek (view the top element of the stack)
char Stack::peek()
{
    if (top == -1)
    {
        return '\0';
    }
    return arr[top];
}