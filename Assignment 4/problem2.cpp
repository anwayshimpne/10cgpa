#include <iostream>
using namespace std;

class Node {
public:
    int coeff;   // Coefficient
    int power;   // Power of x
    Node* next;

    Node(int c, int p) {
        coeff = c;
        power = p;
        next = NULL;
    }
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() { head = NULL; }

    // Function to insert term in decreasing order of power
    void insertTerm(int c, int p) {
        Node* newNode = new Node(c, p);

        if (head == NULL || head->power < p) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL && temp->next->power >= p)
                temp = temp->next;

            if (temp->power == p) {
                temp->coeff += c;  // Combine like terms
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    // Function to display polynomial
    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "0";
            return;
        }

        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->power;
            if (temp->next != NULL && temp->next->coeff >= 0)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to add two polynomials
    Polynomial add(Polynomial P2) {
        Polynomial result;
        Node *p1 = head, *p2 = P2.head;

        while (p1 != NULL && p2 != NULL) {
            if (p1->power == p2->power) {
                result.insertTerm(p1->coeff + p2->coeff, p1->power);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->power > p2->power) {
                result.insertTerm(p1->coeff, p1->power);
                p1 = p1->next;
            } else {
                result.insertTerm(p2->coeff, p2->power);
                p2 = p2->next;
            }
        }

        while (p1 != NULL) {
            result.insertTerm(p1->coeff, p1->power);
            p1 = p1->next;
        }

        while (p2 != NULL) {
            result.insertTerm(p2->coeff, p2->power);
            p2 = p2->next;
        }

        return result;
    }
};

int main() {
    Polynomial P1, P2, P3;
    int n, coeff, power;

    cout << "=========================================\n";
    cout << "   POLYNOMIAL ADDITION USING LINKED LIST\n";
    cout << "=========================================\n";

    cout << "\nEnter number of terms for first polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and power: ";
        cin >> coeff >> power;
        P1.insertTerm(coeff, power);
    }

    cout << "\nEnter number of terms for second polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and power: ";
        cin >> coeff >> power;
        P2.insertTerm(coeff, power);
    }

    cout << "\nFirst Polynomial: ";
    P1.display();

    cout << "Second Polynomial: ";
    P2.display();

    P3 = P1.add(P2);

    cout << "\nResultant Polynomial (P1 + P2): ";
    P3.display();

    return 0;
}
