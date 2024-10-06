// Name : Virang Raje 
// Roll No. : 34
// Enrollment No. : ADT23SOCB1320
// Create binary tree and perform Inorder, Preorder and Postorder non recursive traversal.

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
    void inorder_non(Node*);
    void preorder_non(Node*);
    void postorder_non(Node*);
    Node* getRoot() { return root; } 
};

Node* BinaryTree::getNode() {
    Node* temp;
    temp = new Node;
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
        }

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

        cout << "Do you want to insert any more nodes in BT? (1/0): ";
        cin >> repeat;
    } while (repeat == 1);
}

void BinaryTree::inorder_non(Node* root) {
    Node* current = root;
    Node* s[100];
    int top = -1;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            s[++top] = current;
            current = current->lchild;
        }

        current = s[top--];
        cout << current->data << " ";
        current = current->rchild;
    }
}

void BinaryTree::preorder_non(Node* root) {
    Node* current = root;
    Node* s[100];
    int top = -1;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            cout << current->data << " ";
            s[++top] = current;
            current = current->lchild;
        }

        current = s[top--];
        current = current->rchild;
    }
}

void BinaryTree::postorder_non(Node* root) {
    Node* current = root;
    Node* s[100];
    Node* lastVisited = NULL;
    int top = -1;

    while (current != NULL || top != -1) {
        if (current != NULL) {
            s[++top] = current;
            current = current->lchild;
        } else {
            Node* peekNode = s[top];
            if (peekNode->rchild != NULL && lastVisited != peekNode->rchild) {
                current = peekNode->rchild;
            } else {
                cout << peekNode->data << " ";
                lastVisited = s[top--];
            }
        }
    }
}

int main() {
    BinaryTree bt;
    bt.create();  // Assuming this function creates or initializes the binary tree

    int choice;
    while(1){
        cout << "Enter your choice:" << endl;
        cout << "Inorder Traversal - 1 " << endl;
        cout << "Preorder Traversal - 2 " << endl;
        cout << "Postorder Traversal - 3 " << endl;
        cout << "Exit - 4 " << endl;
        cin >> choice;

        switch (choice) {
            case 1: 
                bt.inorder_non(bt.getRoot());
                cout << endl;
                break;

            case 2: 
                bt.preorder_non(bt.getRoot());
                cout << endl;
                break;

            case 3: 
                bt.postorder_non(bt.getRoot());
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

//Output

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
Enter data: 7
Where do you want to insert element? Left or Right of 5? r
Where do you want to insert element? Left or Right of 6? l
Do you want to insert any more nodes in BT? (1/0): 0
Enter your choice:
Inorder Traversal - 1 
Preorder Traversal - 2 
Postorder Traversal - 3 
Exit - 4 
1
4 5 7 6 
Enter your choice:
Inorder Traversal - 1 
Preorder Traversal - 2 
Postorder Traversal - 3 
Exit - 4 
2
5 4 6 7 
Enter your choice:
Inorder Traversal - 1 
Preorder Traversal - 2 
Postorder Traversal - 3 
Exit - 4 
3
4 7 6 5 
Enter your choice:
Inorder Traversal - 1 
Preorder Traversal - 2 
Postorder Traversal - 3 
Exit - 4 
4
*/