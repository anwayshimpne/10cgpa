// Implement a hash table with collision resolution using linear probing.

#include <iostream>
using namespace std;

class HashTable {
private:
    int *table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1; // -1 means EMPTY
    }

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // Insert with linear probing
    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % size; // move to next slot

            if (index == startIndex) { // table full
                cout << "Hash Table is full! Cannot insert " << key << endl;
                return;
            }
        }

        table[index] = key;
        cout << "Inserted key " << key << " at index " << index << endl;
    }

    // Search key
    void search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
            index = (index + 1) % size;

            if (index == startIndex) break; // searched all
        }

        cout << "Key " << key << " not found!" << endl;
    }

    // Display table
    void display() {
        cout << "\nHash Table contents:\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            if (table[i] == -1)
                cout << "EMPTY";
            else
                cout << table[i];
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
        cout << "\n--- Hash Table (Linear Probing) ---";
        cout << "\n1. Insert Key";
        cout << "\n2. Search Key";
        cout << "\n3. Display Table";
        cout << "\n4. Exit";
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
            ht.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
