// Name : Virang Raje 
// Roll No. : 34
// Enrollment No. : ADT23SOCB1320
// Create binary tree and perform Inorder, Preorder and Postorder recursive traversal.

#include<iostream>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    Node* rchild;
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() { root = NULL; }
    Node* getNode();
    void create();
    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);
    Node* getRoot() { return root; } 
};

Node* BinaryTree::getNode() {
    Node* temp = new Node;
    cout << "Enter data: ";
    cin >> temp->data;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void BinaryTree::create() {
    char choice;
    int repeat;
    Node* newNode = NULL, *current = NULL, *parent = NULL;
    do {
        cout << "Create a new node!" << endl;
        newNode = getNode();

        if (root == NULL) {
            root = newNode;
            cout << "Root node created." << endl;
        } else {
            parent = NULL;
            current = root;

            while (current != NULL) {
                cout << "Where do you want to insert element? Left or Right of " << current->data << "? ";
                cin >> choice;
                parent = current;

                if (choice == 'L' || choice == 'l') {
                    if (current->lchild == NULL) {
                        current->lchild = newNode;
                        break;
                    } else {
                        current = current->lchild;
                    }
                } else if (choice == 'R' || choice == 'r') {
                    if (current->rchild == NULL) {
                        current->rchild = newNode;
                        break;
                    } else {
                        current = current->rchild;
                    }
                } else {
                    cout << "Invalid choice! Enter 'l' or 'r': ";
                    break;
                }
            }
        }

        cout << "Do you want to insert any more nodes in BT? (1/0): ";
        cin >> repeat;
    } while (repeat == 1);
}

void BinaryTree::inorder(Node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        cout << root->data << " ";
        inorder(root->rchild);
    }
}

void BinaryTree::preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void BinaryTree::postorder(Node* root) {
    if (root) {
        postorder(root->lchild);
        postorder(root->rchild);
        cout << root->data << " ";
    }
}

int main() {
    BinaryTree bt;
    bt.create();  // Assuming this function creates or initializes the binary tree

    int choice;
    while (1) {
        cout << "Enter your choice:" << endl;
        cout << "Inorder Traversal - 1 " << endl;
        cout << "Preorder Traversal - 2 " << endl;
        cout << "Postorder Traversal - 3 " << endl;
        cout << "Exit - 4 " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                bt.inorder(bt.getRoot());
                cout << endl;
                break;

            case 2:
                bt.preorder(bt.getRoot());
                cout << endl;
                break;

            case 3:
                bt.postorder(bt.getRoot());
                cout << endl;
                break;

            case 4:
                exit(0);

            default:
                cout << "Enter option between 1 to 4." << endl;
        }
    }

    return 0;
}

// Output

/*
Create a new node!
Enter data: 5
Root node created.
Do you want to insert any more nodes in BT? (1/0): 1
Create a new node!
Enter data: 4
Where do you want to insert element? Left or Right of 5? l
Do you want to insert any more nodes in BT? (1/0): 1
Create a new node!
Enter data: 6
Where do you want to insert element? Left or Right of 5? r
Do you want to insert any more nodes in BT? (1/0): 1
Create a new node!
Enter data: 3
Where do you want to insert element? Left or Right of 5? l
Where do you want to insert element? Left or Right of 4? r
Do you want to insert any more nodes in BT? (1/0): 0
Enter your choice:
Inorder Traversal - 1 
Preorder Traversal - 2 
Postorder Traversal - 3 
Exit - 4 
1
4 3 5 6 
Enter your choice:
Inorder Traversal - 1 
Preorder Traversal - 2 
Postorder Traversal - 3 
Exit - 4 
2
5 4 3 6 
Enter your choice:
Inorder Traversal - 1 
Preorder Traversal - 2 
Postorder Traversal - 3 
Exit - 4 
3
3 4 6 5 
Enter your choice:
Inorder Traversal - 1 
Preorder Traversal - 2 
Postorder Traversal - 3 
Exit - 4 
4
*/