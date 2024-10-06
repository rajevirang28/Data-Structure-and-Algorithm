// Name : Virang Raje 
// Roll No. : 34
// Enrollment No. : ADT23SOCB1320
// Create a Binary Search tree. Print original BST & new tree level wise. Find height & print leaf nodes.

#include<iostream>
using namespace std;

struct Node
{
    Node *lchild;
    int Data;
    Node *rchild;
};

class BinaryTree
{
private:
    Node* root;
public:
    BinaryTree() { root = NULL; }
    Node* getnode();
    void createBT();
    void inorder_recursive();
    void inorder_recursive(Node*);
};

void BinaryTree::inorder_recursive(Node* root)
{
    if (root)
    {
        inorder_recursive(root->lchild);
        cout << root->Data << " ";
        inorder_recursive(root->rchild);
    }
}

void BinaryTree::inorder_recursive()
{
    inorder_recursive(root);
}

Node* BinaryTree::getnode()
{
    Node* newNode = new Node;
    cout << "Enter the Data: ";
    cin >> newNode->Data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

void BinaryTree::createBT()
{
    Node* newNode;
    Node* current;
    Node* parent;
    char choice;
    int repeat;
    do
    {
        newNode = getnode();
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            parent = NULL;
            current = root;
            while (current != NULL)
            {
                cout << "Enter left or right (L/R): ";
                cin >> choice;
                if (choice == 'L' || choice == 'l')
                {
                    if (current->lchild == NULL)
                    {
                        current->lchild = newNode;
                        break;
                    }
                    else
                    {
                        parent = current;
                        current = current->lchild;
                    }
                }
                else if (choice == 'R' || choice == 'r')
                {
                    if (current->rchild == NULL)
                    {
                        current->rchild = newNode;
                        break;
                    }
                    else
                    {
                        parent = current;
                        current = current->rchild;
                    }
                }
                else
                {
                    cout << "Wrong choice" << endl;
                    break;
                }
            }
        }
        cout << "Do you want to insert any more nodes? (1/0): ";
        cin >> repeat;
    }
    while (repeat == 1);
}

int main()
{
    BinaryTree BT;
    BT.createBT();
    cout << "In-order Traversal: ";
    BT.inorder_recursive();
    cout << endl;
    return 0;
}

//Output

/*
Enter the Data: 5
Do you want to insert any more nodes? (1/0): 1
Enter the Data: 4
Enter left or right (L/R): l
Do you want to insert any more nodes? (1/0): 1
Enter the Data: 6
Enter left or right (L/R): r
Do you want to insert any more nodes? (1/0): 1
Enter the Data: 3
Enter left or right (L/R): l
Enter left or right (L/R): l
Do you want to insert any more nodes? (1/0): 1
Enter the Data: 7
Enter left or right (L/R): r
Enter left or right (L/R): r
Do you want to insert any more nodes? (1/0): 0
In-order Traversal: 3 4 5 6 7 
*/