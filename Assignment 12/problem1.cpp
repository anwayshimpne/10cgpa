// WAP to simulate a faculty database as a hash table. 
// Search a particular faculty by using 'divide' as a hash function for linear 
// probing with chaining without replacement method of collision handling technique.
//  Assume suitable data for faculty record.

#include <iostream>
#include <string>
using namespace std;

// Structure to store faculty details
struct Faculty {
    int id;
    string name;
    string dept;
    string phone;
};

// Hash Table Class
class HashTable {
private:
    Faculty* table;
    bool* occupied;
    int size;

    // Hash function using Divide Method
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new Faculty[size];
        occupied = new bool[size];
        for (int i = 0; i < size; i++)
            occupied[i] = false;
    }

    // Insert faculty record using Linear Probing without replacement
    void insertFaculty(int id, string name, string dept, string phone) {
        int index = hashFunction(id);
        int startIndex = index;

        // Linear probing without replacement
        while (occupied[index]) {
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Hash Table Full! Cannot insert record for ID " << id << endl;
                return;
            }
        }

        table[index].id = id;
        table[index].name = name;
        table[index].dept = dept;
        table[index].phone = phone;
        occupied[index] = true;

        cout << "Inserted Faculty ID " << id << " at index " << index << endl;
    }

    // Search for a faculty by ID
    void searchFaculty(int id) {
        int index = hashFunction(id);
        int startIndex = index;

        while (occupied[index]) {
            if (table[index].id == id) {
                cout << "\nFaculty Found at index " << index << ":\n";
                cout << "Faculty ID : " << table[index].id << endl;
                cout << "Name       : " << table[index].name << endl;
                cout << "Department : " << table[index].dept << endl;
                cout << "Phone No.  : " << table[index].phone << endl;
                return;
            }

            index = (index + 1) % size;
            if (index == startIndex)
                break; // full loop, not found
        }

        cout << "\nFaculty with ID " << id << " not found!\n";
    }

    // Display the hash table
    void displayTable() {
        cout << "\nHash Table (Faculty Database - Linear Probing Without Replacement):\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            if (occupied[i]) {
                cout << "[ID: " << table[i].id
                     << ", Name: " << table[i].name
                     << ", Dept: " << table[i].dept
                     << ", Phone: " << table[i].phone << "]";
            } else {
                cout << "EMPTY";
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

    int choice, id;
    string name, dept, phone;

    do {
        cout << "\n--- Faculty Database (Divide Hash + Linear Probing Without Replacement) ---";
        cout << "\n1. Insert Faculty Record";
        cout << "\n2. Search Faculty Record";
        cout << "\n3. Display All Records";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Faculty ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Department: ";
            cin >> dept;
            cout << "Enter Phone Number: ";
            cin >> phone;
            ht.insertFaculty(id, name, dept, phone);
            break;

        case 2:
            cout << "Enter Faculty ID to search: ";
            cin >> id;
            ht.searchFaculty(id);
            break;

        case 3:
            ht.displayTable();
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
