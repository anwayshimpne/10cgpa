#include <iostream>
using namespace std;

struct Node {
    string customerName;
    Node* next;
};

class CallQueue {
    Node* front;
    Node* rear;

public:
    CallQueue() {
        front = rear = NULL;
    }

    // Enqueue: Add new call
    void enqueue(string name) {
        Node* temp = new Node();
        temp->customerName = name;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Call from " << name << " added to queue.\n";
    }

    // Dequeue: Remove call for service agent
    void dequeue() {
        if (front == NULL) {
            cout << "No calls in queue. Agents waiting...\n";
            return;
        }

        Node* temp = front;
        cout << "Connecting call of: " << temp->customerName << endl;

        front = front->next;
        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // Display all waiting calls
    void display() {
        if (front == NULL) {
            cout << "No calls waiting.\n";
            return;
        }

        Node* temp = front;
        cout << "Current waiting calls:\n";
        while (temp != NULL) {
            cout << " - " << temp->customerName << endl;
            temp = temp->next;
        }
    }
};

int main() {
    CallQueue cq;
    int choice;
    string name;

    while (true) {
        cout << "\n--- Call Center System ---\n";
        cout << "1. New incoming call\n";
        cout << "2. Agent takes next call\n";
        cout << "3. Display waiting calls\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                cq.enqueue(name);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cq.display();
                break;

            case 4:
                cout << "System closing...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
