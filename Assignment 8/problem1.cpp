#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int marks;
    Node* left;
    Node* right;

    Node(string n, int m) {
        name = n;
        marks = m;
        left = right = NULL;
    }
};

class BST {
public:
    Node* insert(Node* root, string name, int marks) {
        if (root == NULL)
            return new Node(name, marks);

        if (marks < root->marks)
            root->left = insert(root->left, name, marks);
        else
            root->right = insert(root->right, name, marks);

        return root;
    }

    void assignRollNos(Node* root, int &roll) {
        if (root == NULL) return;

        // Reverse inorder: Right → Root → Left
        assignRollNos(root->right, roll);

        cout << "Roll No. " << roll << " -> "
             << root->name << " (" << root->marks << " marks)" << endl;
        roll++;

        assignRollNos(root->left, roll);
    }
};

int main() {
    BST tree;
    Node* root = NULL;

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    string name;
    int marks;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;

        root = tree.insert(root, name, marks);
    }

    int roll = 1;
    cout << "\n--- Roll Numbers Assigned (Topper = Roll No. 1) ---\n";
    tree.assignRollNos(root, roll);

    return 0;
}
