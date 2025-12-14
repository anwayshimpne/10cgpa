// Write a program to illustrate operations on a BST holding numeric keys.
// The menu must include: • Insert • Delete • Find • Show


#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

class BST {
public:
    Node* insert(Node* root, int key) {
        if (root == NULL)
            return new Node(key);

        if (key < root->key)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);

        return root;
    }

    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) {
            cout << "Key not found!\n";
            return root;
        }

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }

        return root;
    }

    bool find(Node* root, int key) {
        if (root == NULL) return false;

        if (root->key == key) return true;
        else if (key < root->key) return find(root->left, key);
        else return find(root->right, key);
    }

    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
};

int main() {
    BST tree;
    Node* root = NULL;

    int choice, key;

    while (true) {
        cout << "\n\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find\n";
        cout << "4. Show (Inorder Traversal)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            root = tree.insert(root, key);
            cout << "Inserted successfully!";
            break;

        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            root = tree.deleteNode(root, key);
            break;

        case 3:
            cout << "Enter key to find: ";
            cin >> key;
            if (tree.find(root, key))
                cout << "Key found!";
            else
                cout << "Key NOT found!";
            break;

        case 4:
            cout << "BST (Inorder): ";
            tree.inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.";
        }
    }

    return 0;
}
