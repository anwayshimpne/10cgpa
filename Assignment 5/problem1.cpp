#include <iostream>
using namespace std;

// Node structure for stack
class Node {
public:
    int price;
    Node* next;

    Node(int p) {
        price = p;
        next = NULL;
    }
};

// Stack implemented using linked list
class StockStack {
private:
    Node* top; // points to the top of the stack

public:
    StockStack() {
        top = NULL;
    }

    // 1. record(price) – Add a new stock price
    void record(int price) {
        Node* newNode = new Node(price);
        newNode->next = top;
        top = newNode;
        cout << " Recorded stock price: " << price << endl;
    }

    // 2. remove() – Remove and return the most recent price
    void remove() {
        if (isEmpty()) {
            cout << "  No stock prices to remove.\n";
            return;
        }
        Node* temp = top;
        cout << "  Removed most recent price: " << temp->price << endl;
        top = top->next;
        delete temp;
    }

    // 3. latest() – Return most recent stock price
    void latest() {
        if (isEmpty()) {
            cout << " No stock prices recorded yet.\n";
            return;
        }
        cout << " Latest recorded stock price: " << top->price << endl;
    }

    // 4. isEmpty() – Check if stack is empty
    bool isEmpty() {
        return (top == NULL);
    }

    // Display all recorded prices
    void display() {
        if (isEmpty()) {
            cout << "  No stock prices recorded.\n";
            return;
        }

        cout << " Stock Price History (most recent first): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->price;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    StockStack tracker;
    int choice, price;

    cout << "============================================\n";
    cout << "   STOCK PRICE TRACKER USING STACK (LINKED LIST)\n";
    cout << "============================================\n";

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Record new stock price\n";
        cout << "2. Remove most recent price\n";
        cout << "3. View latest price\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Display price history\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter stock price to record: ";
            cin >> price;
            tracker.record(price);
            break;
        case 2:
            tracker.remove();
            break;
        case 3:
            tracker.latest();
            break;
        case 4:
            if (tracker.isEmpty())
                cout << " No prices recorded (stack is empty).\n";
            else
                cout << " Prices are recorded (stack not empty).\n";
            break;
        case 5:
            tracker.display();
            break;
        case 6:
            cout << "Exiting program... Thank you!\n";
            break;
        default:
            cout << " Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
