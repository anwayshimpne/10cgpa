#include <iostream>
#include <queue>
using namespace std;

struct Patient {
    string name;
    int id;
};

int main() {
    queue<Patient> q;
    int choice, idCounter = 1;

    while (true) {
        cout << "\n--- Medical Clinic Queue System ---\n";
        cout << "1. Check-in Patient\n";
        cout << "2. Assign Patient to Doctor\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            // Patient check-in
            Patient p;
            cout << "Enter patient name: ";
            cin >> p.name;
            p.id = idCounter++;
            q.push(p);
            cout << "Patient " << p.name << " (ID: " << p.id << ") checked in.\n";
        }
        else if (choice == 2) {
            // Assign patient to doctor
            if (q.empty()) {
                cout << "No patients waiting.\n";
            } else {
                Patient p = q.front();
                q.pop();
                cout << "Assigning patient " << p.name 
                     << " (ID: " << p.id << ") to doctor.\n";
            }
        }
        else if (choice == 3) {
            // Display all waiting patients
            if (q.empty()) {
                cout << "No patients in the queue.\n";
            } else {
                queue<Patient> temp = q; // copy queue for display
                cout << "Patients in queue:\n";
                while (!temp.empty()) {
                    Patient p = temp.front();
                    temp.pop();
                    cout << p.id << " - " << p.name << endl;
                }
            }
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
