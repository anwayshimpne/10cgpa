#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct StudentRecord {
    int roll;
    string name;
    string dept;
    float cgpa;
    string company;
    float salary;
    bool isDeleted;

    StudentRecord() {
        roll = -1;
        isDeleted = false;
    }
};

class HashTable {
private:
    vector<StudentRecord> table;
    int size;
    int count;
    const int PRIME = 7; // used for second hash function

    // Primary hash function
    int hash1(int key) const {
        return key % size;
    }

    // Secondary hash function for double hashing
    int hash2(int key) const {
        return PRIME - (key % PRIME);
    }

    // Load factor calculation
    float loadFactor() const {
        return (float)count / size;
    }

    // Rehashing function (doubles table size)
    void rehash() {
        cout << "\n[Rehashing triggered: Table expanding from " << size << " to " << size * 2 << "]\n";

        vector<StudentRecord> oldTable = table;
        size = nextPrime(size * 2); // expand to next prime
        table.clear();
        table.resize(size);
        count = 0;

        for (auto &rec : oldTable) {
            if (rec.roll != -1 && !rec.isDeleted) {
                insertRecord(rec.roll, rec.name, rec.dept, rec.cgpa, rec.company, rec.salary);
            }
        }
    }

    // Utility to find next prime number
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    int nextPrime(int n) {
        while (!isPrime(n)) n++;
        return n;
    }

public:
    // Constructor
    HashTable(int s = 11) {
        size = s;
        table.resize(size);
        count = 0;
    }

    // Insert record using double hashing
    void insertRecord(int roll, string name, string dept, float cgpa, string company, float salary) {
        if (loadFactor() > 0.7) rehash();

        int index = hash1(roll);
        int step = hash2(roll);
        int start = index;
        int i = 0;

        while (table[index].roll != -1 && !table[index].isDeleted) {
            i++;
            index = (start + i * step) % size;
        }

        table[index].roll = roll;
        table[index].name = name;
        table[index].dept = dept;
        table[index].cgpa = cgpa;
        table[index].company = company;
        table[index].salary = salary;
        table[index].isDeleted = false;
        count++;

        cout << "Inserted Record for Roll No " << roll << " at index " << index << endl;
    }

    // Search record by roll number
    void searchRecord(int roll) {
        int index = hash1(roll);
        int step = hash2(roll);
        int start = index;
        int i = 0;

        while (table[index].roll != -1) {
            if (!table[index].isDeleted && table[index].roll == roll) {
                cout << "\nRecord Found at index " << index << ":\n";
                cout << "Roll No  : " << table[index].roll << endl;
                cout << "Name     : " << table[index].name << endl;
                cout << "Dept     : " << table[index].dept << endl;
                cout << "CGPA     : " << table[index].cgpa << endl;
                cout << "Company  : " << table[index].company << endl;
                cout << "Salary   : " << table[index].salary << endl;
                return;
            }
            i++;
            index = (start + i * step) % size;
        }

        cout << "Record not found for Roll No: " << roll << endl;
    }

    // Delete record
    void deleteRecord(int roll) {
        int index = hash1(roll);
        int step = hash2(roll);
        int start = index;
        int i = 0;

        while (table[index].roll != -1) {
            if (!table[index].isDeleted && table[index].roll == roll) {
                table[index].isDeleted = true;
                cout << "Record deleted for Roll No: " << roll << endl;
                return;
            }
            i++;
            index = (start + i * step) % size;
        }
        cout << "Record not found for deletion!\n";
    }

    // Display all records
    void displayTable() {
        cout << "\n-------------------------------------------------------------\n";
        cout << "Index\tRoll\tName\tDept\tCGPA\tCompany\t\tSalary\n";
        cout << "-------------------------------------------------------------\n";
        for (int i = 0; i < size; i++) {
            if (table[i].roll != -1 && !table[i].isDeleted)
                cout << i << "\t" << table[i].roll << "\t" << table[i].name << "\t"
                     << table[i].dept << "\t" << table[i].cgpa << "\t"
                     << table[i].company << "\t" << table[i].salary << endl;
            else
                cout << i << "\tEMPTY\n";
        }
    }
};

// ---------- main() ----------
int main() {
    HashTable portal;
    int choice, roll;
    string name, dept, company;
    float cgpa, salary;

    do {
        cout << "\n====== SMART COLLEGE PLACEMENT PORTAL (Advanced Hashing) ======";
        cout << "\n1. Insert Student Record";
        cout << "\n2. Search Student Record";
        cout << "\n3. Delete Student Record";
        cout << "\n4. Display All Records";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll No: "; cin >> roll;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Department: "; cin >> dept;
            cout << "Enter CGPA: "; cin >> cgpa;
            cout << "Enter Company Placed: "; cin >> company;
            cout << "Enter Salary: "; cin >> salary;
            portal.insertRecord(roll, name, dept, cgpa, company, salary);
            break;

        case 2:
            cout << "Enter Roll No to search: ";
            cin >> roll;
            portal.searchRecord(roll);
            break;

        case 3:
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            portal.deleteRecord(roll);
            break;

        case 4:
            portal.displayTable();
            break;

        case 5:
            cout << "Exiting Smart Portal...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
