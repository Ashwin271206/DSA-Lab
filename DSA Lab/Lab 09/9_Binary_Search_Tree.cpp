// C++ program to implement Binary Search Tree ADT using linked list
#include <iostream>
#include <string.h>
using namespace std;

class Tree
{
private:
    struct node
    {
        char data;
        struct node *left;
        struct node *right;
    } *root;

public:
    Tree();
    node *getRoot();
    void insert(char);
    void preorder(node *root);
    void inorder(node *root);
    void postorder(node *root);
    char search(char);
};

int main()
{
    int choice;
    char val;
    Tree tree;
    do
    {
        cout << "\n\nMENU :\n 1. Insert\n 2. Preorder\n 3. Inorder\n 4. Postorder\n 5. Search\n 6. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> val;
            tree.insert(val);
            cout << "Insertion Successful." << endl;
            break;

        case 2:
            tree.preorder(tree.getRoot());
            break;

        case 3:
            tree.inorder(tree.getRoot());
            break;

        case 4:
            tree.postorder(tree.getRoot());
            break;

        case 5:
            cout << "Enter element to search for : ";
            cin >> val;
            if (tree.search(val))
            {
                cout << "Element found !!" << endl;
            }
            else
            {
                cout << "Element not found !!" << endl;
            }
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

// Constructor function to initialize root to NULL
Tree::Tree()
{
    root = NULL;
}

// Getter function to get root
Tree::node *Tree::getRoot()
{
    return root;
}

// Function to insert an element in order
void Tree::insert(char val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        return;
    }
    node *temp = root;
    node *parent = NULL;
    while (temp != NULL)
    {
        parent = temp;
        if (val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (val < parent->data)
    {
        parent->left = newnode;
    }
    else
    {
        parent->right = newnode;
    }
}

// Function to display the tree in preorder format
void Tree::preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    preorder(root->left);
    preorder(root->right);
}

// Function to display the tree in inorder format
void Tree::inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << "  ";
    inorder(root->right);
}

// Function to display the tree in postorder format
void Tree::postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "  ";
}

// Function to search for an element
char Tree::search(char val)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (val == temp->data)
        {
            return val;
        }
        else if (val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return '\0';
}