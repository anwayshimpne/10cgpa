#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert node at the end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display list
    void display(Node* node) {
        if (node == NULL) {
            cout << "Empty list\n";
            return;
        }
        while (node != NULL) {
            cout << node->data;
            if (node->next != NULL)
                cout << " -> ";
            node = node->next;
        }
        cout << endl;
    }

    Node* getHead() { return head; }

    // Function to split the list into front and back halves
    void frontBackSplit(Node* source, Node** frontRef, Node** backRef) {
        if (source == NULL || source->next == NULL) {
            *frontRef = source;
            *backRef = NULL;
            return;
        }

        Node* slow = source;
        Node* fast = source->next;

        // Move 'fast' two nodes and 'slow' one node at a time
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Split the list
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    LinkedList list;
    int n, val;

    cout << "=====================================\n";
    cout << " FRONT–BACK SPLIT OF LINKED LIST\n";
    cout << "=====================================\n";

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        list.insert(val);
    }

    cout << "\nOriginal List: ";
    list.display(list.getHead());

    Node* front = NULL;
    Node* back = NULL;

    list.frontBackSplit(list.getHead(), &front, &back);

    cout << "\nFront Half: ";
    list.display(front);

    cout << "Back Half: ";
    list.display(back);

    return 0;
}
