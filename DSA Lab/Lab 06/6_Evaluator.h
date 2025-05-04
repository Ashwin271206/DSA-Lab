// Header file of functions to convert infix to postfix and evaluate them
#include <iostream>
#include <cctype>
using namespace std;

// StackADT using Linked List with integer data
struct node
{
    int data;
    struct node *next;
};

class Stack
{
private:
    node *top;

public:
    Stack();
    void push(int);
    int pop();
    int peek();
};

// Constructor function to initialize top to NULL
Stack::Stack()
{
    top = NULL;
}

// Function to push a value into the stack
void Stack::push(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        cout << "Memory Allocation Failed." << endl;
        return;
    }
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

// Functon to pop the top element from the stack
int Stack::pop()
{
    if (top == NULL)
    {
        return -1;
    }
    int value = top->data;
    node *temp = top;
    top = top->next;
    free(temp);
    return value;
}

// Function to peek (view the top element)
int Stack::peek()
{
    if (top == NULL)
    {
        return -1;
    }
    return top->data;
}

string infix;
string postfix;

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '=')
        return 1;
    if (op == '+' || op == '-')
        return 2;
    if (op == '*' || op == '/' || op == '%')
        return 3;
    return 0;
}

// Function to check if character is an operator
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=';
}

// Function to convert an infix expression to postfix expression
void toPostfix(string infix, string &postfix)
{
    Stack stack;
    postfix = "";
    for (char ch : infix)
    {
        if (isdigit(ch))
        {
            postfix += ch;
        }
        else if (isOperator(ch))
        {
            while (stack.peek() != -1 && precedence((char)stack.peek()) >= precedence(ch))
            {
                postfix += (char)stack.pop();
            }
            stack.push(ch);
        }
        else if (ch == '(')
        {
            stack.push(ch);
        }
        else if (ch == ')')
        {
            while (stack.peek() != -1 && (char)stack.peek() != '(')
            {
                postfix += (char)stack.pop();
            }
            stack.pop();
        }
    }
    while (stack.peek() != -1)
    {
        postfix += (char)stack.pop();
    }
}

// Function to evaluate a postfix expression
double evaluate(string postfix)
{
    Stack stack;
    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            stack.push(ch - '0');
        }
        else
        {
            int val2 = stack.pop();
            int val1 = stack.pop();
            switch (ch)
            {
            case '+':
                stack.push(val1 + val2);
                break;
            case '-':
                stack.push(val1 - val2);
                break;
            case '*':
                stack.push(val1 * val2);
                break;
            case '/':
                stack.push(val1 / val2);
                break;
            case '%':
                stack.push(val1 % val2);
                break;
            case '=':
                stack.push(val2);
                break;
            }
        }
    }
    return stack.pop();
}