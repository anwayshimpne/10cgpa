#include <iostream>
using namespace std;

// Doubly linked list node
class Node {
public:
    int data;       // will store binary digit (0 or 1)
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

// Binary number using Doubly Linked List
class BinaryNumber {
public:
    Node* head;
    Node* tail;

    BinaryNumber() {
        head = tail = NULL;
    }

    // Function to insert a binary digit at the end
    void insertBit(int bit) {
        Node* newNode = new Node(bit);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display the binary number
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Create and return 1’s complement
    BinaryNumber onesComplement() {
        BinaryNumber result;
        Node* temp = head;
        while (temp) {
            result.insertBit(temp->data == 0 ? 1 : 0);
            temp = temp->next;
        }
        return result;
    }

    // Create and return 2’s complement
    BinaryNumber twosComplement() {
        BinaryNumber oneComp = onesComplement();
        BinaryNumber result;

        Node* temp = oneComp.tail;
        int carry = 1;

        // Traverse from LSB to MSB
        while (temp) {
            int sum = temp->data + carry;
            result.insertBit(sum % 2);
            carry = sum / 2;
            temp = temp->prev;
        }
        if (carry == 1)
            result.insertBit(1);

        // Reverse to correct order
        result.reverse();
        return result;
    }

    // Reverse the linked list (used for correct display order)
    void reverse() {
        Node* curr = head;
        Node* temp = NULL;
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp)
            head = temp->prev;
    }

    // Add two binary numbers and return result
    static BinaryNumber add(BinaryNumber b1, BinaryNumber b2) {
        BinaryNumber result;
        Node* t1 = b1.tail;
        Node* t2 = b2.tail;

        int carry = 0;
        while (t1 != NULL || t2 != NULL || carry != 0) {
            int bit1 = (t1 ? t1->data : 0);
            int bit2 = (t2 ? t2->data : 0);
            int sum = bit1 + bit2 + carry;

            result.insertBit(sum % 2);
            carry = sum / 2;

            if (t1) t1 = t1->prev;
            if (t2) t2 = t2->prev;
        }

        result.reverse();
        return result;
    }
};

// Main function
int main() {
    BinaryNumber num1, num2;

    cout << "Enter first binary number: ";
    string bin1;
    cin >> bin1;
    for (char c : bin1)
        num1.insertBit(c - '0');

    cout << "\nStored Binary Number 1: ";
    num1.display();

    cout << "1's Complement: ";
    BinaryNumber oneComp = num1.onesComplement();
    oneComp.display();

    cout << "2's Complement: ";
    BinaryNumber twoComp = num1.twosComplement();
    twoComp.display();

    cout << "\nEnter second binary number: ";
    string bin2;
    cin >> bin2;
    for (char c : bin2)
        num2.insertBit(c - '0');

    cout << "\nStored Binary Number 2: ";
    num2.display();

    cout << "Addition Result: ";
    BinaryNumber sum = BinaryNumber::add(num1, num2);
    sum.display();

    return 0;
}
