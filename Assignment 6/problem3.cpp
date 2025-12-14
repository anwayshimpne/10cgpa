#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> passengers;
    int choice;
    string name;

    while (true) {
        cout << "\n--- Ticket Agent Queue System ---\n";
        cout << "1. Add Passenger to Queue\n";
        cout << "2. Display Passenger at Front\n";
        cout << "3. Remove Passenger from Front\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter passenger name: ";
            cin >> name;
            passengers.push(name);
            cout << name << " added to the queue.\n";
        }
        else if (choice == 2) {
            if (passengers.empty()) {
                cout << "Queue is empty.\n";
            } else {
                cout << "Front Passenger: " << passengers.front() << endl;
            }
        }
        else if (choice == 3) {
            if (passengers.empty()) {
                cout << "No passenger to remove.\n";
            } else {
                cout << "Removing: " << passengers.front() << endl;
                passengers.pop();
            }
        }
        else if (choice == 4) {
            cout << "\nProgram terminating...\n";
            cout << "Passengers left in queue: " << passengers.size() << endl;
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
