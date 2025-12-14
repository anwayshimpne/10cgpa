#include <iostream>
#include <string>
using namespace std;

class GNode {
public:
    int flag;         // 0 = atom, 1 = sublist
    string data;
    GNode* next;
    GNode* down;

    GNode() {
        flag = 0;
        next = NULL;
        down = NULL;
    }
};

class GLL {
public:
    GNode* create() {
        GNode *head = NULL, *last = NULL;
        string token;

        while (true) {
            cin >> token;
            if (token == ")") // end current list
                break;

            GNode* node = new GNode();
            if (token == "(") {
                node->flag = 1;
                node->down = create(); // recursively create sublist
            } else {
                node->flag = 0;
                node->data = token;
            }

            if (head == NULL)
                head = node;
            else
                last->next = node;
            last = node;
        }

        return head;
    }

    void display(GNode* node) {
        cout << "{";
        while (node != NULL) {
            if (node->flag == 0)
                cout << node->data;
            else
                display(node->down);

            if (node->next != NULL)
                cout << ", ";
            node = node->next;
        }
        cout << "}";
    }
};

int main() {
    cout << "===========================================\n";
    cout << "   SET IMPLEMENTATION USING GLL STRUCTURE\n";
    cout << "===========================================\n";
    cout << "Enter elements (use '(' to start sublist and ')' to end):\n";

    GLL obj;
    cout << "Example Input: p q ( r s t ( ) ( u v ) w x ( y z ) a1 b1 ) )\n\n";

    GNode* head = obj.create();

    cout << "\nGeneralized Linked List Representation:\n";
    obj.display(head);
    cout << endl;
    return 0;
}
