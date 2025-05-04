// C++ program to implement queue ADT using a linked list
#include <iostream>
using namespace std;

class Queue
{
private:
    struct node
    {
        int data;
        struct node *next;
    } *front, *rear;

public:
    Queue();
    void enqueue(int);
    int dequeue();
    int peek();
};

int main()
{
    int choice, val;
    Queue queue;
    do
    {
        cout << "\n\nMENU :\n 1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue : ";
            cin >> val;
            queue.enqueue(val);
            cout << "Enqueue Successful." << endl;
            break;

        case 2:
            val = queue.dequeue();
            if (val == -1)
            {
                cout << "Dequeue failed. Queue Empty." << endl;
            }
            else
            {
                cout << "Dequeue Successful. Deleted value : " << val << endl;
            }
            break;

        case 3:
            val = queue.peek();
            if (val == -1)
            {
                cout << "Queue Empty." << endl;
            }
            else
            {
                cout << "Front --> " << val << endl;
            }
            break;

        case 4:
            cout << "Exiting code." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    } while (choice != 4);
}

// Constructor function to initialize top to NULL
Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

// Function to enqueue a value into the Queue
// Time complexity = O(1)
void Queue::enqueue(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

// Function to dequeue the first element from the Queue
// Time complexity = O(1)
int Queue::dequeue()
{
    if (front == NULL)
    {
        return -1;
    }
    int value = front->data;
    node *temp = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return value;
}

// Function to peek (view the topmost element of the Queue)
// Time complexity = O(1)
int Queue::peek()
{
    if (front == NULL)
    {
        return -1;
    }
    return (front->data);
}