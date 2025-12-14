// Write a Program to create a Binary Tree Search and Find Minimum/Maximum in BST

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Find Minimum
int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

// Find Maximum
int findMax(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return -1;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}
// Level-wise display (simple inorder)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main() {
    Node* root = NULL;
    int choice, value;
    while (true) {
        cout << "\n---- BST MENU ----\n";
        cout << "1. Insert\n";
        cout << "2. Find Minimum\n";
        cout << "3. Find Maximum\n";
        cout << "4. Display (Inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "Minimum value: " << findMin(root) << endl;
            break;
        case 3:
            cout << "Maximum value: " << findMax(root) << endl;
            break;
        case 4:
            cout << "BST (Inorder): ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
