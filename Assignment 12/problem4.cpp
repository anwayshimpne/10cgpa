#include <iostream>
#include <string>
using namespace std;

// Structure for Student record
struct Student {
    int roll;
    string name;
    string dept;
    float marks;
    bool isDeleted; // for lazy deletion
};

// Hash Table Class
class HashTable {
private:
    Student* table;
    bool* occupied;
    int size;

    // Hash Function (MOD method)
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new Student[size];
        occupied = new bool[size];
        for (int i = 0; i < size; i++) {
            occupied[i] = false;
            table[i].isDeleted = false;
        }
    }

    // Insert new record
    void insertRecord(int roll, string name, string dept, float marks) {
        int index = hashFunction(roll);
        int start = index;

        while (occupied[index] && !table[index].isDeleted) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Hash Table Full! Cannot insert record for Roll No: " << roll << endl;
                return;
            }
        }

        table[index].roll = roll;
        table[index].name = name;
        table[index].dept = dept;
        table[index].marks = marks;
        table[index].isDeleted = false;
        occupied[index] = true;

        cout << "Record inserted for Roll No: " << roll << " at index " << index << endl;
    }

    // Search record by Roll Number
    void searchRecord(int roll) {
        int index = hashFunction(roll);
        int start = index;

        while (occupied[index]) {
            if (!table[index].isDeleted && table[index].roll == roll) {
                cout << "\nRecord Found at index " << index << ":\n";
                cout << "Roll No: " << table[index].roll << endl;
                cout << "Name   : " << table[index].name << endl;
                cout << "Dept   : " << table[index].dept << endl;
                cout << "Marks  : " << table[index].marks << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }

        cout << "\nRecord not found for Roll No: " << roll << endl;
    }

    // Delete record by Roll Number
    void deleteRecord(int roll) {
        int index = hashFunction(roll);
        int start = index;

        while (occupied[index]) {
            if (!table[index].isDeleted && table[index].roll == roll) {
                table[index].isDeleted = true; // lazy delete
                cout << "Record deleted for Roll No: " << roll << " at index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }

        cout << "Record not found for deletion!\n";
    }

    // Display all records
    void displayTable() {
        cout << "\nHash Table (Student Database):\n";
        cout << "Index\tRoll\tName\tDept\tMarks\tStatus\n";
        cout << "----------------------------------------------\n";
        for (int i = 0; i < size; i++) {
            cout << i << "\t";
            if (occupied[i]) {
                if (table[i].isDeleted)
                    cout << "Deleted\n";
                else
                    cout << table[i].roll << "\t" << table[i].name << "\t"
                         << table[i].dept << "\t" << table[i].marks << "\tActive\n";
            } else {
                cout << "EMPTY\n";
            }
        }
    }
};

// ---------- main() ----------
int main() {
    int size;
    cout << "Enter hash table size: ";
    cin >> size;

    HashTable ht(size);
    int choice, roll;
    string name, dept;
    float marks;

    do {
        cout << "\n--- Student Database Management System (Hash Table) ---";
        cout << "\n1. Insert Record";
        cout << "\n2. Search Record";
        cout << "\n3. Delete Record";
        cout << "\n4. Display All Records";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll No: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Department: ";
            cin >> dept;
            cout << "Enter Marks: ";
            cin >> marks;
            ht.insertRecord(roll, name, dept, marks);
            break;

        case 2:
            cout << "Enter Roll No to search: ";
            cin >> roll;
            ht.searchRecord(roll);
            break;

        case 3:
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            ht.deleteRecord(roll);
            break;

        case 4:
            ht.displayTable();
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
