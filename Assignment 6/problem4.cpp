#include <iostream>
using namespace std;

#define MAX 50

struct Queue {
    int arr[MAX];
    int front, rear;
};

void init(Queue &q) {
    q.front = q.rear = -1;
}

bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

bool isEmpty(Queue q) {
    return q.front == -1;
}

void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "Queue Overflow!\n";
        return;
    }
    if (isEmpty(q)) {
        q.front = q.rear = 0;
    } else {
        q.rear++;
    }
    q.arr[q.rear] = value;
    cout << "Inserted: " << value << endl;
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow!\n";
        return;
    }
    cout << "Deleted: " << q.arr[q.front] << endl;
    if (q.front == q.rear) {
        q.front = q.rear = -1; // Empty queue
    } else {
        q.front++;
    }
}

void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Queue q1, q2;
    init(q1);
    init(q2);

    int qChoice, choice, value;

    while (true) {
        cout << "\n--- Select Queue ---\n";
        cout << "1. Queue 1\n";
        cout << "2. Queue 2\n";
        cout << "3. Exit\n";
        cin >> qChoice;

        if (qChoice == 3)
            break;

        Queue *selected = (qChoice == 1) ? &q1 : &q2;

        cout << "\n--- Operations ---\n";
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(*selected, value);
                break;
            case 2:
                dequeue(*selected);
                break;
            case 3:
                display(*selected);
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}

