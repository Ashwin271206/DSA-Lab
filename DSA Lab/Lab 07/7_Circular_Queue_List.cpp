// C++ program to perfrom Circular Queue implementation using a list
#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue
{
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue();
    bool enqueue(int);
    int dequeue();
    int peek();
};

int main()
{
    int choice, val;
    CircularQueue queue;
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
            if (queue.enqueue(val) == 0)
            {
                cout << "Queue is full. Enqueue failed." << endl;
            }
            else
            {
                cout << "Enqueue Successful." << endl;
            }
            break;

        case 2:
            val = queue.dequeue();
            if (val == -1)
            {
                cout << "Dequeue failed. Queue is empty." << endl;
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

// Constructor function to initialize front and rear to -1
CircularQueue::CircularQueue()
{
    front = -1;
    rear = -1;
}

// Function to enqueue an element into the queue
// Time complexity = O(1)
bool CircularQueue::enqueue(int val)
{
    if (front == (rear + 1) % SIZE)
    {
        return 0;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    arr[rear] = val;
    return 1;
}

// Function to dequeue the last element from the queue
// Time complexity = O(1)
int CircularQueue::dequeue()
{
    if (front == -1)
    {
        return -1;
    }
    int del = arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
    return del;
}

// Function to peek (display front element of queue)
// Time complexity = O(1)
int CircularQueue::peek()
{
    if (front == -1)
    {
        return -1;
    }
    return arr[front];
}
