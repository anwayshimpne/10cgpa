#include <iostream>
#include <string>
using namespace std;

// Faculty record structure
struct Faculty {
    int id;
    string name;
    string dept;
    string phone;
    int chain;  // To create logical chain link (index of next record)
};

// Hash table class implementing MOD hash + Linear Probing with Replacement
class HashTable {
private:
    Faculty* table;
    bool* occupied;
    int size;

    // Hash function using MOD method
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new Faculty[size];
        occupied = new bool[size];
        for (int i = 0; i < size; i++) {
            occupied[i] = false;
            table[i].chain = -1; // -1 = no next link
        }
    }

    // Insert record with replacement
    void insertFaculty(int id, string name, string dept, string phone) {
        int index = hashFunction(id);

        // If slot empty -> place directly
        if (!occupied[index]) {
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].phone = phone;
            occupied[index] = true;
            table[index].chain = -1;
            cout << "Inserted Faculty ID " << id << " at index " << index << endl;
            return;
        }

        // Collision occurs
        int existingHash = hashFunction(table[index].id);
        if (existingHash != index) {
            // Existing record doesn't belong here → Replace it
            cout << "Collision: Replacing record ID " << table[index].id
                 << " with new record ID " << id << " (With Replacement)\n";

            // Save old record
            Faculty temp = table[index];

            // Insert new record in its rightful place
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].phone = phone;
            table[index].chain = -1;
            occupied[index] = true;

            // Reinsert displaced record
            insertWithoutReplacement(temp.id, temp.name, temp.dept, temp.phone);
        } else {
            // Same hash area → place new record in next free slot (chain link)
            int next = (index + 1) % size;
            while (occupied[next]) {
                next = (next + 1) % size;
                if (next == index) {
                    cout << "Hash Table Full! Cannot insert record for ID " << id << endl;
                    return;
                }
            }
            table[next].id = id;
            table[next].name = name;
            table[next].dept = dept;
            table[next].phone = phone;
            table[next].chain = -1;
            occupied[next] = true;

            // Update chain link
            int temp = index;
            while (table[temp].chain != -1)
                temp = table[temp].chain;
            table[temp].chain = next;

            cout << "Inserted Faculty ID " << id << " at index " << next << " (Chained)\n";
        }
    }

    // Helper: insert without replacement (for displaced record)
    void insertWithoutReplacement(int id, string name, string dept, string phone) {
        int index = hashFunction(id);
        int next = index;

        while (occupied[next]) {
            next = (next + 1) % size;
            if (next == index) {
                cout << "Hash Table Full! Cannot insert record for displaced ID " << id << endl;
                return;
            }
        }

        table[next].id = id;
        table[next].name = name;
        table[next].dept = dept;
        table[next].phone = phone;
        table[next].chain = -1;
        occupied[next] = true;

        // Update chain link from original hash index
        int temp = index;
        while (table[temp].chain != -1)
            temp = table[temp].chain;
        table[temp].chain = next;

        cout << "Reinserted displaced record ID " << id << " at index " << next << endl;
    }

    // Search record
    void searchFaculty(int id) {
        int index = hashFunction(id);
        int temp = index;

        while (temp != -1) {
            if (occupied[temp] && table[temp].id == id) {
                cout << "\nFaculty Found at index " << temp << ":\n";
                cout << "Faculty ID : " << table[temp].id << endl;
                cout << "Name       : " << table[temp].name << endl;
                cout << "Department : " << table[temp].dept << endl;
                cout << "Phone No.  : " << table[temp].phone << endl;
                return;
            }
            temp = table[temp].chain;
        }
        cout << "\nFaculty with ID " << id << " not found!\n";
    }

    // Display entire table
    void displayTable() {
        cout << "\nHash Table (Linear Probing with Chaining + Replacement):\n";
        cout << "Index\tID\tName\tDept\tPhone\tChain\n";
        cout << "-------------------------------------------------------\n";
        for (int i = 0; i < size; i++) {
            if (occupied[i])
                cout << i << "\t" << table[i].id << "\t" << table[i].name
                     << "\t" << table[i].dept << "\t" << table[i].phone
                     << "\t" << table[i].chain << endl;
            else
                cout << i << "\tEMPTY\n";
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
        cout << "\n--- Faculty Database (Linear Probing with Chaining + Replacement) ---";
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
            cout << "Enter Phone: ";
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
