// Store and retrieve student records using roll numbers.

#include <iostream>
#include <string>
using namespace std;

// Structure to store student details
struct Student {
    int roll;
    string name;
    string dept;
    float marks;
    Student* next;
};

// Hash Table Class
class HashTable {
private:
    Student** table;  // array of linked lists
    int size;

    // Hash function (using roll number)
    int hashFunction(int roll) {
        return roll % size;
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new Student*[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    // Insert student record
    void insertStudent(int roll, string name, string dept, float marks) {
        int index = hashFunction(roll);
        Student* newStudent = new Student{roll, name, dept, marks, nullptr};

        if (table[index] == nullptr) {
            table[index] = newStudent;
        } else {
            // Collision → add to linked list (end)
            Student* temp = table[index];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newStudent;
        }

        cout << "Record inserted for Roll No: " << roll << " at index " << index << endl;
    }

    // Search student record by roll number
    void searchStudent(int roll) {
        int index = hashFunction(roll);
        Student* temp = table[index];

        while (temp != nullptr) {
            if (temp->roll == roll) {
                cout << "\nRecord Found:\n";
                cout << "Roll No: " << temp->roll << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Department: " << temp->dept << endl;
                cout << "Marks: " << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "\nRecord not found for Roll No: " << roll << endl;
    }

    // Display all records
    void displayAll() {
        cout << "\nHash Table (Student Records):\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            Student* temp = table[i];

            if (temp == nullptr) {
                cout << "EMPTY";
            } else {
                while (temp != nullptr) {
                    cout << "[Roll: " << temp->roll << ", Name: " << temp->name
                         << ", Dept: " << temp->dept << ", Marks: " << temp->marks << "] -> ";
                    temp = temp->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }

    // Delete a record
    void deleteStudent(int roll) {
        int index = hashFunction(roll);
        Student* temp = table[index];
        Student* prev = nullptr;

        while (temp != nullptr && temp->roll != roll) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Record not found for deletion!" << endl;
            return;
        }

        if (prev == nullptr) {
            table[index] = temp->next;  // delete head
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Record deleted for Roll No: " << roll << endl;
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
        cout << "\n--- Student Record Hash Table ---";
        cout << "\n1. Insert Student Record";
        cout << "\n2. Search Student Record";
        cout << "\n3. Delete Student Record";
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
            ht.insertStudent(roll, name, dept, marks);
            break;

        case 2:
            cout << "Enter Roll No to search: ";
            cin >> roll;
            ht.searchStudent(roll);
            break;

        case 3:
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            ht.deleteStudent(roll);
            break;

        case 4:
            ht.displayAll();
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
