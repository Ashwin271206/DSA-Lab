// C++ program to perfrom Priority Queue implementation
#include <iostream>
#include <vector>
using namespace std;

class Priority_Queue
{
private:
    int size;
    vector<int> vec;

public:
    Priority_Queue();
    void display();
    void insert(int);
    int remove();
    int search(int);
    void sort();
};

int main()
{
    int choice;
    int val;
    Priority_Queue pq;
    do
    {
        cout << "\n\nMENU :\n 1. Insert\n 2. Delete\n 3. Display\n 4. Search\n 5. Sort\n 6. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> val;
            pq.insert(val);
            cout << "Insertion Successful." << endl;
            break;

        case 2:
            val = pq.remove();
            if (val != -1)
            {
                cout << "Deletion successful. Deleted value : " << val;
            }
            else
            {
                cout << "Deletion failed. Queue is empty." << endl;
            }
            break;

        case 3:
            pq.display();
            break;

        case 4:
            cout << "Enter element to search for : ";
            cin >> val;
            if (pq.search(val))
            {
                cout << "Element found." << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
            break;

        case 5:
            pq.sort();
            cout << "Queue Sorted. Enter 3 to display." << endl;
            break;

        case 6:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    } while (choice != 6);
}

// Function to swap two integers (not a part of class)
// Time complexity = O(1)
void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// Constructor function to initialize size
Priority_Queue::Priority_Queue()
{
    size = 0;
}

// Function to display the priority queue
// Time complexity = O(n)
void Priority_Queue::display()
{
    if (size == 0)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << "  ";
    }
}

// Function to insert an element into the Priority Queue
// Time complexity = O(nlogn) to insert n elements
void Priority_Queue::insert(int num)
{
    vec.push_back(num);
    int index = size;
    while (index > 0 && vec[index] > vec[(index - 1) / 2])
    {
        swap(vec[index], vec[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    size++;
}

// Function to delete an element from the Priority Queue
// Time complexity = O(nlogn) to remove n elements
int Priority_Queue::remove()
{
    if (size == 0)
    {
        return -1;
    }
    int del = vec[0];
    size--;
    swap(vec[0], vec[size]);
    vec.pop_back();
    int index = 0;
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int greater = index;
        if (left < size && vec[left] > vec[greater])
        {
            greater = left;
        }
        if (right < size && vec[right] > vec[greater])
        {
            greater = right;
        }
        if (greater == index)
        {
            break;
        }
        swap(vec[index], vec[greater]);
        index = greater;
    }
    return del;
}

// Function to search for an element in the Priority Queue
// Time complexity = O(n)
int Priority_Queue::search(int num)
{
    for (int i = 0; i < size; i++)
    {
        if (vec[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to implement heapsort
// Time complexity = O(nlogn)
void Priority_Queue::sort()
{
    if (size == 0)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    int temp = size;
    for (int i = temp; i > 0; i--)
    {
        vec[i - 1] = remove();
    }
    size = temp;
}