#include <iostream>
using namespace std;

#define MAX 5   // maximum number of orders allowed

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Place order (enqueue)
    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Cannot place order " << orderID << ". Pizza Parlour is FULL.\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = orderID;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    // Serve order (dequeue)
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Order " << arr[front] << " served.\n";

        if (front == rear) {
            // Only one element left
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Display orders
    void display() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, orderID;

    cout << "Pizza Parlour Order System (FCFS using Circular Queue)\n";

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Pending Orders\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                cq.placeOrder(orderID);
                break;

            case 2:
                cq.serveOrder();
                break;
            case 3:
                cq.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 4);
    return 0;
}
