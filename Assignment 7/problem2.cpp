// Write a program to perform Binary Search Tree (BST) operations 
// (Count the total number of nodes, Compute the height of the BST, Mirror Image ).

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return root;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Count total number of nodes
int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Compute height of BST
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// Mirror image of BST
Node* mirror(Node* root) {
    if (root == NULL)
        return NULL;

    // Swap left and right subtrees
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);

    return root;
}

// Inorder Traversal
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
        cout << "\n--- BST Operations ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Count Total Nodes\n";
        cout << "3. Compute Height of BST\n";
        cout << "4. Display Mirror Image (Inorder)\n";
        cout << "5. Display Inorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Total Nodes = " << countNodes(root) << endl;
            break;

        case 3:
            cout << "Height of BST = " << height(root) << endl;
            break;

        case 4:
            mirror(root);
            cout << "Mirror Image (Inorder): ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }
}