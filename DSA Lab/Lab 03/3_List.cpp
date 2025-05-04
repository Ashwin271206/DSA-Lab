// C++ program to perfrom list implementation (insertion, deletion, search, rotate, display)
#include <iostream>
#include <cstdlib>
using namespace std;

// Creating class list with all functions
class list
{
private:
    int size;
    int *arr = (int *)malloc(5 * sizeof(int));

public:
    list();
    void display();
    bool insertBeg(int);
    bool insertEnd(int);
    bool insertPos(int, int);
    int deleteBeg();
    int deleteEnd();
    int deletePos(int);
    int search(int);
    void reverse(int, int);
    bool rotate(int);
};

int main()
{
    int choice, stop = 0;
    int num, pos;
    list list_1; // Creating class object
    while (!stop)
    {
        cout << "\n\nMENU :"; // Printing menu
        cout << "\n 1. Insertion in Beginning\n 2. Insertion in End\n 3. Insertion at Position";
        cout << "\n 4. Deletion in Beginning\n 5. Deletion in End\n 6. Deletion at Position";
        cout << "\n 7. Search in Array \n 8. Display Array\n 9. Rotate Array\n 10. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter element to insert : ";
            cin >> num;
            if (list_1.insertBeg(num) == 0)
            {
                cout << "Insertion failed." << endl;
            }
            else
            {
                cout << "Insertion successful. Enter 8 to display." << endl;
            }
            break;
        case 2:
            cout << "\nEnter element to insert : ";
            cin >> num;
            if (list_1.insertEnd(num) == 0)
            {
                cout << "Insertion failed." << endl;
            }
            else
            {
                cout << "Insertion successful. Enter 8 to display." << endl;
            }
            break;
        case 3:
            cout << "\nEnter element to insert : ";
            cin >> num;
            cout << "Enter position to insert : ";
            cin >> pos;

            if (list_1.insertPos(num, pos) == 0)
            {
                cout << "Insertion failed." << endl;
            }
            else
            {
                cout << "Insertion successful. Enter 8 to display." << endl;
            }
            break;
        case 4:
            num = list_1.deleteBeg();
            if (num == -1)
            {
                cout << "Deletion failed." << endl;
            }
            else
            {
                cout << "Deletion successful.\nDeleted element : " << num;
            }
            break;
        case 5:
            num = list_1.deleteEnd();
            if (num == -1)
            {
                cout << "Deletion failed." << endl;
            }
            else
            {
                cout << "Deletion successful.\nDeleted element : " << num;
            }
            break;
        case 6:
            cout << "\nEnter position to delete : ";
            cin >> pos;
            num = list_1.deletePos(pos);

            if (num == -1)
            {
                cout << "Deletion failed." << endl;
            }
            else
            {
                cout << "Deletion successful.\nDeleted element : " << num;
            }

            break;
        case 7:
            cout << "\nEnter element to search for : ";
            cin >> num;
            pos = list_1.search(num);
            if (pos == -1)
            {
                cout << "Search failed." << endl;
            }
            else
            {
                cout << "Search successful.\nElement found at index : " << pos;
            }
            break;
        case 8:
            list_1.display();
            break;
        case 9:
            cout << "\nEnter number of times to rotate : ";
            cin >> num;
            if (list_1.rotate(num) == 0)
            {
                cout << "Rotation failed." << endl;
            }
            else
            {
                cout << "Rotation successful. Enter 8 to display." << endl;
            }
            break;
        case 10:
            stop = 1;
            cout << "Exitting code." << endl;
            break;
        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    }
}

// Constructor function to initialize size
list::list()
{
    size = 0;
}

// Function to display array
void list::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}

// Function to insert element in beginning of array
bool list::insertBeg(int num)
{
    if (size >= 5)
    {
        cout << "\nArray is full." << endl;
        return 0;
    }
    else
    {
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = num;
        size++;
        return 1;
    }
}

// Function to insert element in end of array
bool list::insertEnd(int num)
{
    if (size >= 5)
    {
        cout << "\nArray is full." << endl;
        return 0;
    }
    else
    {
        arr[size] = num;
        size++;
        return 1;
    }
}

// Function to insert element at a position
bool list::insertPos(int num, int pos)
{
    if (size >= 5)
    {
        cout << "\nArray is full." << endl;
        return 0;
    }
    else
    {
        if (pos > size || pos < 0)
        {
            cout << "\nInvalid Position." << endl;
            return 0;
        }
        else
        {

            for (int i = size; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = num;
            size++;
            return 1;
        }
    }
}

// Function to delete first element
int list::deleteBeg()
{
    if (size <= 0)
    {
        cout << "\nArray is empty." << endl;
        return -1;
    }
    else
    {
        int temp = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return temp;
    }
}

// Function to delete last element
int list::deleteEnd()
{
    if (size <= 0)
    {
        cout << "\nArray is empty." << endl;
        return -1;
    }

    else
    {
        int temp = arr[size - 1];
        size--;
        return temp;
    }
}

// Function to delete the element at the specific position
int list::deletePos(int pos)
{
    if (size <= 0)
    {
        cout << "\nArray is empty." << endl;
        return -1;
    }
    else
    {
        if (pos >= size || pos < 0)
        {
            cout << "\nInvalid Position." << endl;
            return -1;
        }
        else
        {
            int temp = arr[pos];
            for (int i = pos; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            return temp;
        }
    }
}

// Linear search function to search for an element
int list::search(int num)
{
    if (size <= 0)
    {
        cout << "\nArray is empty." << endl;
        return -1;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == num)
            {
                return i;
            }
        }
        cout << "\nElement not found." << endl;
        return -1;
    }
}

// Function to reverse a part of an array
void list::reverse(int first, int last)
{
    while (first < last)
    {
        int temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;
        first++;
        last--;
    }
}

// Function to rotate an array n times
bool list::rotate(int num)
{
    if (size <= 0)
    {
        cout << "\nArray is empty." << endl;
        return 0;
    }
    else
    {
        num %= size;
        if (num)
        {
            reverse(0, size - 1);
            reverse(0, num - 1);
            reverse(num, size - 1);
        }
        return 1;
    }
}