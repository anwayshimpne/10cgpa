#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Structure for Employee / Faculty record
struct Employee {
    int id;
    string name;
    string dept;
    float salary;
};

// Hash Table class
class HashTable {
private:
    Employee* table;
    bool* occupied;
    int size;

    // --- Hash function: Mid-Square Method ---
    int midSquareHash(int key) {
        long long square = (long long)key * key; // Step 1: square the key
        string s = to_string(square);           // Step 2: convert to string

        // Step 3: extract middle digits
        int len = s.length();
        int mid = len / 2;

        string midDigits;
        if (len >= 4)
            midDigits = s.substr(mid - 2, 3);   // take 3 middle digits
        else
            midDigits = s;

        int middleNum = stoi(midDigits);
        return middleNum % size;                // Step 4: modulo table size
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new Employee[size];
        occupied = new bool[size];
        for (int i = 0; i < size; i++)
            occupied[i] = false;
    }

    // Insert employee record
    void insertRecord(int id, string name, string dept, float salary) {
        int index = midSquareHash(id);
        int start = index;

        // Linear probing
        while (occupied[index]) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Hash Table Full! Cannot insert record for ID " << id << endl;
                return;
            }
        }

        table[index].id = id;
        table[index].name = name;
        table[index].dept = dept;
        table[index].salary = salary;
        occupied[index] = true;

        cout << "Inserted Employee ID " << id << " at index " << index << endl;
    }

    // Search employee by ID
    void searchRecord(int id) {
        int index = midSquareHash(id);
        int start = index;

        while (occupied[index]) {
            if (table[index].id == id) {
                cout << "\nRecord Found at index " << index << ":\n";
                cout << "Employee ID : " << table[index].id << endl;
                cout << "Name        : " << table[index].name << endl;
                cout << "Department  : " << table[index].dept << endl;
                cout << "Salary      : " << table[index].salary << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break; // Full loop
        }

        cout << "\nEmployee with ID " << id << " not found!\n";
    }

    // Display all records
    void displayTable() {
        cout << "\nHash Table (Mid-Square Hash + Linear Probing):\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            if (occupied[i]) {
                cout << "[ID: " << table[i].id
                     << ", Name: " << table[i].name
                     << ", Dept: " << table[i].dept
                     << ", Salary: " << table[i].salary << "]";
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
    string name, dept;
    float salary;

    do {
        cout << "\n--- Employee Database (Mid-Square Hash + Linear Probing) ---";
        cout << "\n1. Insert Employee Record";
        cout << "\n2. Search Employee Record";
        cout << "\n3. Display All Records";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Department: ";
            cin >> dept;
            cout << "Enter Salary: ";
            cin >> salary;
            ht.insertRecord(id, name, dept, salary);
            break;

        case 2:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            ht.searchRecord(id);
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
