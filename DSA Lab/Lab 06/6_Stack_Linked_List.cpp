// C++ program to implement stack ADT using a linked list
#include <iostream>
using namespace std;

class Stack
{
private:
    struct node
    {
        char data;
        struct node *next;
    } *top;

public:
    Stack();
    void push(char);
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
            s1.push(val);
            cout << "Push Successful." << endl;
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
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    }
}

// Constructor function to initialize top to NULL
Stack::Stack()
{
    top = NULL;
}

// Function to push a value into the stack
void Stack::push(char val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

// Functon to pop the top element from the stack
char Stack::pop()
{
    if (top == NULL)
    {
        return '\0';
    }
    char value = top->data;
    node *temp = top;
    top = top->next;
    free(temp);
    return value;
}

// Function to peek (view the top element)
char Stack::peek()
{
    if (top == NULL)
    {
        return '\0';
    }
    return top->data;
}