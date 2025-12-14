#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() { head = NULL; }

    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "NULL <-> ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        cout << "Inserted " << value << " at beginning.\n";
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            cout << "Inserted " << value << " as first element.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << value << " at end.\n";
    }

    // Insert after specific node
    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node with data " << key << " not found.\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;

        cout << "Inserted " << value << " after " << key << ".\n";
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;

        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        if (temp->next == NULL) {
            cout << "Deleted " << temp->data << " from end.\n";
            delete temp;
            head = NULL;
            return;
        }

        while (temp->next != NULL)
            temp = temp->next;

        cout << "Deleted " << temp->data << " from end.\n";
        temp->prev->next = NULL;
        delete temp;
    }

    // Delete specific node
    void deleteSpecific(int key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node with data " << key << " not found.\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        cout << "Deleted node with data " << key << ".\n";
        delete temp;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    DoublyLinkedList dll;
    int choice, value, key;

    cout << "===============================================\n";
    cout << "  DOUBLY LINKED LIST IMPLEMENTATION (INSERT/DELETE)\n";
    cout << "===============================================\n";

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Display List\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            dll.display();
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            dll.insertAtBeginning(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            dll.insertAtEnd(value);
            break;
        case 4:
            cout << "Enter node value after which to insert: ";
            cin >> key;
            cout << "Enter new value to insert: ";
            cin >> value;
            dll.insertAfter(key, value);
            break;
        case 5:
            dll.deleteFromBeginning();
            break;
        case 6:
            dll.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value of node to delete: ";
            cin >> key;
            dll.deleteSpecific(key);
            break;
        case 8:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
