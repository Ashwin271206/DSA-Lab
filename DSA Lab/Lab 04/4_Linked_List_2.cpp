// C++ program to perform operations such as insertion in ascending order, merging and display on linked lists
#include <iostream>
#include "4_Linked_List_2.h" // Header file contains the class definition, data members and member functions
using namespace std;

int main()
{
    int num, choice, stop = 0;
    list l1, l2, l3;
    while (!stop)
    {
        cout << "\n\nMENU :";
        cout << "\n 1. Insert in List 1\n 2. Insert in List 2\n 3. Merge both Lists\n 4. Display all Lists\n 5. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> num;
            l1.insertAsc(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 2:
            cout << "Enter value to insert : ";
            cin >> num;
            l2.insertAsc(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 3:
            l3.merge(l1, l2);
            cout << "Merge successful." << endl;
            break;

        case 4:
            cout << "\nList 1 : " << endl;
            l1.display();
            cout << "\nList 2 : " << endl;
            l2.display();
            cout << "\nList 3 : " << endl;
            l3.display();
            break;

        case 5:
            stop = 1;
            cout << "Exitting code." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    }
}
