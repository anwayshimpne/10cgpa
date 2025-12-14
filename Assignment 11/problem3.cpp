//  Implement collision resolution using linked lists.

#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// HashTable class using Linked Lists for collision resolution
class HashTable {
private:
    Node** table;  // Array of pointers (each points to a linked list)
    int size;

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    // Insert key into hash table
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node{key, nullptr};

        // If no linked list exists at this index
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            // Append to existing linked list (end)
            Node* temp = table[index];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }

        cout << "Inserted key " << key << " at index " << index << endl;
    }

    // Search key in hash table
    void search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key " << key << " not found!" << endl;
    }

    // Delete key from hash table
    void remove(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Key " << key << " not found for deletion!" << endl;
            return;
        }

        if (prev == nullptr) {
            // Delete head node
            table[index] = temp->next;
        } else {
            // Bypass node
            prev->next = temp->next;
        }

        delete temp;
        cout << "Key " << key << " deleted from index " << index << endl;
    }

    // Display entire hash table
    void display() {
        cout << "\nHash Table (Collision Resolution using Linked Lists):\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            if (temp == nullptr) {
                cout << "EMPTY";
            } else {
                while (temp != nullptr) {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

// ---------- main() ----------
int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);
    int choice, key;

    do {
        cout << "\n--- Hash Table (Linked List Collision Handling) ---";
        cout << "\n1. Insert Key";
        cout << "\n2. Search Key";
        cout << "\n3. Delete Key";
        cout << "\n4. Display Table";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
            break;

        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.remove(key);
            break;

        case 4:
            ht.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
