// C++ program to implement Graph ADT (adjacency list)
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *next;
};

class Graph
{
private:
    int vertices;
    vector<node *> adjacency_list;

public:
    Graph(int);
    bool insert(int, int);
    bool remove(int, int);
    bool search(int, int);
    void display();
};

int main()
{
    int choice;
    int x, y, result, vertices;
    cout << "\n Enter number of vertices : ";
    cin >> vertices;
    Graph graph(vertices);
    do
    {
        cout << "\n\nMENU :\n 1. Insert\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter vertices : ";
            cin >> x >> y;
            if (graph.insert(x, y))
            {
                cout << "Insertion successful." << endl;
            }
            else
            {
                cout << "Insertion failed." << endl;
            }
            break;

        case 2:
            cout << "Enter vertices : ";
            cin >> x >> y;
            result = graph.remove(x, y);
            if (result)
            {
                cout << "Deletion successful." << endl;
            }
            else
            {
                cout << "Deletion failed." << endl;
            }
            break;

        case 3:
            cout << "Enter vertices : ";
            cin >> x >> y;
            result = graph.search(x, y);
            if (result)
            {
                cout << "Edge found." << endl;
            }
            else
            {
                cout << "Edge does not exist." << endl;
            }
            break;

        case 4:
            graph.display();
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    } while (choice != 5);
}

// Constructor function to initialize the size of adjacency list
Graph::Graph(int num)
{
    vertices = num;
    adjacency_list.resize(vertices, NULL);
}

// Function to display the graph
void Graph::display()
{
    cout << "\n Adjacency List : " << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << "Vertex " << i << " : ";
        node *cur = adjacency_list[i];
        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
}

// Function to insert an edge
bool Graph::insert(int x, int y)
{
    if (x >= vertices || y >= vertices || x < 0 || y < 0)
    {
        return 0;
    }

    node *cur = adjacency_list[x];
    while (cur != NULL)
    {
        if (cur->data == y)
        {
            return 0;
        }
        cur = cur->next;
    }

    node *newNode = new node;
    newNode->data = y;
    newNode->next = adjacency_list[x];
    adjacency_list[x] = newNode;

    node *newNode2 = new node;
    newNode2->data = x;
    newNode2->next = adjacency_list[y];
    adjacency_list[y] = newNode2;
    return 1;
}

// Function to delete an edge
bool Graph::remove(int x, int y)
{
    if (x >= vertices || y >= vertices || x < 0 || y < 0)
    {
        return 0;
    }

    bool found = 0;
    node *cur = adjacency_list[x];
    node *prev = NULL;
    while (cur != NULL)
    {
        if (cur->data == y)
        {
            if (prev == NULL)
            {
                adjacency_list[x] = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            delete cur;
            found = 1;
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    node *cur2 = adjacency_list[y];
    node *prev2 = NULL;
    while (cur2 != NULL)
    {
        if (cur2->data == x)
        {
            if (prev2 == NULL)
            {
                adjacency_list[y] = cur2->next;
            }
            else
            {
                prev2->next = cur2->next;
            }
            delete cur2;
            found = 1;
            break;
        }
        prev2 = cur2;
        cur2 = cur2->next;
    }
    return found;
}

// Function to search for an edge
bool Graph::search(int x, int y)
{
    if (x >= vertices || y >= vertices || x < 0 || y < 0)
    {
        return 0;
    }

    node *cur = adjacency_list[x];
    while (cur != NULL)
    {
        if (cur->data == y)
        {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}
