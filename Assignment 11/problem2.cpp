// Implement collision handling using separate chaining.

#include <iostream>
#include <list>   // For linked list
using namespace std;

class HashTable {
private:
    int size;              // number of buckets
    list<int> *table;      // array of linked lists

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new list<int>[size];
    }

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // Insert key
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted key " << key << " at index " << index << endl;
    }

    // Search key
    void search(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
        }
        cout << "Key " << key << " not found!" << endl;
    }

    // Delete key
    void remove(int key) {
        int index = hashFunction(key);
        auto it = table[index].begin();
        while (it != table[index].end()) {
            if (*it == key) {
                it = table[index].erase(it);
                cout << "Key " << key << " deleted from index " << index << endl;
                return;
            } else {
                ++it;
            }
        }
        cout << "Key " << key << " not found for deletion!" << endl;
    }

    // Display table
    void display() {
        cout << "\nHash Table (Separate Chaining):\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            if (table[i].empty()) {
                cout << "EMPTY";
            } else {
                for (auto x : table[i]) {
                    cout << x << " -> ";
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);

    int choice, key;
    do {
        cout << "\n--- Hash Table (Separate Chaining) ---";
        cout << "\n1. Insert Key";
        cout << "\n2. Search Key";
        cout << "\n3. Delete Key";
        cout << "\n4. Display Table";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
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
