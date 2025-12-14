#include <iostream>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = next = NULL;
    }
};

// Class for doubly linked list operations
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    // Insert node at end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Bubble sort algorithm on doubly linked list
    void bubbleSort() {
        if (head == NULL)
            return;

        bool swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    // Swap the data values (you could also swap nodes)
                    int temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
};

// ================= MAIN FUNCTION =================
int main() {
    DoublyLinkedList dll;
    int n, value;

    cout << "=========================================\n";
    cout << "  BUBBLE SORT USING DOUBLY LINKED LIST\n";
    cout << "=========================================\n";

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        dll.insert(value);
    }

    cout << "\nOriginal List:\n";
    dll.display();

    dll.bubbleSort();

    cout << "\nSorted List (Ascending Order):\n";
    dll.display();

    return 0;
}
