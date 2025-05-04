// Header file
#include <iostream>
using namespace std;

class list
{
private:
    struct node
    {
        int data;
        struct node *next;
    } *head;
    typedef struct node node;

public:
    list();
    node *getHead();
    void display();
    void insertAsc(int);
    void merge(list, list);
};

// Constructor function to initialize head to NULL
list::list()
{
    head = NULL;
}

// Getter function to access the head
list::node *list::getHead()
{
    return head;
}

// Function to display the linked list
void list::display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to insert an element in the linked list based on ascending order
void list::insertAsc(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    if (head == NULL || num <= head->data)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL && num > temp->next->data)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to merge 2 linked lists into one single linked list
void list::merge(list l1, list l2)
{
    head = NULL;
    node *temp1 = l1.getHead();
    node *temp2 = l2.getHead();
    node *tail = NULL;
    while (temp1 && temp2)
    {
        node *newNode = (node *)malloc(sizeof(node));
        if (temp1->data < temp2->data)
        {
            newNode->data = temp1->data;
            temp1 = temp1->next;
        }
        else
        {
            newNode->data = temp2->data;
            temp2 = temp2->next;
        }
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    while (temp1)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = temp1->data;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = temp2->data;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        temp2 = temp2->next;
    }
}
