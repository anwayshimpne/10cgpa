#include <iostream>
#include <string>
using namespace std;

// Node structure for BST
class Node {
public:
    int emp_id;
    string emp_name;
    float emp_salary;
    Node* left;
    Node* right;

    Node(int id, string name, float salary) {
        emp_id = id;
        emp_name = name;
        emp_salary = salary;
        left = right = NULL;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    Node* insert(Node* node, int id, string name, float salary) {
        if (node == NULL)
            return new Node(id, name, salary);

        if (id < node->emp_id)
            node->left = insert(node->left, id, name, salary);
        else if (id > node->emp_id)
            node->right = insert(node->right, id, name, salary);
        else
            cout << "⚠️ Duplicate Employee ID not allowed!\n";

        return node;
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << "EmpID: " << node->emp_id
             << " | Name: " << node->emp_name
             << " | Salary: " << node->emp_salary << endl;
        inorder(node->right);
    }

    Node* search(Node* node, int id) {
        if (node == NULL || node->emp_id == id)
            return node;
        if (id < node->emp_id)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

public:
    BST() { root = NULL; }

    void insertEmployee(int id, string name, float salary) {
        root = insert(root, id, name, salary);
    }

    void displaySorted() {
        cout << "\nEmployee Records (Sorted by EmpID):\n";
        cout << "-------------------------------------\n";
        inorder(root);
    }

    void searchEmployee(int id) {
        Node* result = search(root, id);
        if (result == NULL)
            cout << "❌ Employee with ID " << id << " not found.\n";
        else {
            cout << "\n✅ Employee Found:\n";
            cout << "EmpID: " << result->emp_id
                 << " | Name: " << result->emp_name
                 << " | Salary: " << result->emp_salary << endl;
        }
    }
};

// ================= MAIN FUNCTION =================
int main() {
    BST empTree;
    int choice, id;
    string name;
    float salary;

    cout << "==============================================\n";
    cout << " EMPLOYEE RECORD MANAGEMENT USING TREE (BST)\n";
    cout << "==============================================\n";

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Insert Employee Record\n";
        cout << "2. Display All (Sorted by EmpID)\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin >> name;
            cout << "Enter Employee Salary: ";
            cin >> salary;
            empTree.insertEmployee(id, name, salary);
            break;

        case 2:
            empTree.displaySorted();
            break;

        case 3:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            empTree.searchEmployee(id);
            break;

        case 4:
            cout << "Exiting program... Thank you!\n";
            break;

        default:
            cout << "⚠️ Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
