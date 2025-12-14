// Write a program to perform Binary Search Tree (BST) operations (Create, Insert, Delete,Levelwise display )
#include <iostream>
using namespace std;

#define MAX 100

int bst[MAX];

// Initialize BST
void createBST() {
    for (int i = 0; i < MAX; i++)
        bst[i] = -1; // -1 means empty
}

// Insert into BST
void insert(int value) {
    int i = 1;

    while (i < MAX) {
        if (bst[i] == -1) {
            bst[i] = value;
            return;
        }
        else if (value < bst[i])
            i = i * 2;        // Move left
        else
            i = i * 2 + 1;    // Move right
    }

    cout << "Tree overflow! Cannot insert.\n";
}

// Find minimum value index in subtree
int findMinIndex(int index) {
    while (index * 2 < MAX && bst[index * 2] != -1)
        index = index * 2;
    return index;
}

// Delete node
int deleteNode(int index, int value) {
    if (index >= MAX || bst[index] == -1)
        return -1;

    // Traverse left or right
    if (value < bst[index])
        deleteNode(index * 2, value);

    else if (value > bst[index])
        deleteNode(index * 2 + 1, value);

    else {
        // Case 1: No children
        if (bst[index * 2] == -1 && bst[index * 2 + 1] == -1) {
            bst[index] = -1;
        }

        // Case 2: One child
        else if (bst[index * 2] == -1) {
            bst[index] = bst[index * 2 + 1];
            deleteNode(index * 2 + 1, bst[index]);
        }
        else if (bst[index * 2 + 1] == -1) {
            bst[index] = bst[index * 2];
            deleteNode(index * 2, bst[index]);
        }

        // Case 3: Two children
        else {
            int minIndex = findMinIndex(index * 2 + 1);
            bst[index] = bst[minIndex];
            deleteNode(minIndex, bst[minIndex]);
        }
    }
    return 1;
}

// Display Level-wise
void levelOrder() {
    cout << "\nLevel-wise BST:\n";
    for (int i = 1; i < MAX; i++) {
        if (bst[i] != -1)
            cout << "Index " << i << ": " << bst[i] << "\n";
    }
}

int main() {
    createBST();

    int choice, value;

    while (true) {
        cout << "\n--- BST ARRAY MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Level-wise Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(1, value);
            break;

        case 3:
            levelOrder();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
