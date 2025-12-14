#include <iostream>
using namespace std;

class Node {
public:
    int prn;
    string name;
    Node* next;

    Node(int prn, string name) {
        this->prn = prn;
        this->name = name;
        this->next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Add President at beginning
    void addPresident(int prn, string name) {
        Node* newNode = new Node(prn, name);
        newNode->next = head;
        head = newNode;
        cout << "President added: " << name << endl;
    }

    // Add Secretary at end
    void addSecretary(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (head == NULL) {
            head = newNode;
            cout << "Secretary added: " << name << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Secretary added: " << name << endl;
    }


    void addMember(int prn, string name) {
        if (head == NULL || head->next == NULL) {
            cout << "Please add President and Secretary first!" << endl;
            return;
        }
        Node* newNode = new Node(prn, name);
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Member added: " << name << endl;
    }

    
    void display() {
        if (head == NULL) {
            cout << "No members!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Club Members:" << endl;
        cout << "PRN\tName" << endl;
        while (temp != NULL) {
            cout << temp->prn << "\t" << temp->name << endl;
          temp =temp -> next;
        }
    }

    // Count members
    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    // Search by PRN
    void search(int prn) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->prn == prn) {
                cout << "Found: " << temp->name << " (PRN: " << prn << ")" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "PRN not found!" << endl;
    }

    // Delete by PRN
    void deleteMember(int prn) {
        if (head == NULL) return;
        if (head->prn == prn) {
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Deleted President!" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->prn != prn) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "PRN not found!" << endl;
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Member deleted!" << endl;
    }

    // Reverse list
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout << "List reversed!" << endl;
    }

    // Sort list by PRN
    void sortList() {
        if (head == NULL || head->next == NULL) return;
        for (Node* i = head; i->next != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->prn > j->prn) {
                    swap(i->prn, j->prn);
                    swap(i->name, j->name);
                }
            }
        }
        cout << "List sorted by PRN!" << endl;
    }

    // Concatenate two lists
    void concatenate(LinkedList& l2) {
        if (head == NULL) {
            head = l2.head;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = l2.head;
        cout << "Lists concatenated!" << endl;
    }
};

int main() {
    LinkedList club1, club2;
    int choice, prn;
    string name;

    do {
        cout << "\n--- Vertex Club Menu ---" << endl;
        cout << "1. Add President\n2. Add Secretary\n3. Add Member\n4. Display\n5. Count\n6. Search by PRN\n7. Delete by PRN\n8. Reverse\n9. Sort\n10. Concatenate two lists\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter PRN & Name: ";
            cin >> prn >> name;
            club1.addPresident(prn, name);
            break;
        case 2:
            cout << "Enter PRN & Name: ";
            cin >> prn >> name;
            club1.addSecretary(prn, name);
            break;
        case 3:
            cout << "Enter PRN & Name: ";
            cin >> prn >> name;
            club1.addMember(prn, name);
            break;
        case 4:
            club1.display();
            break;
        case 5:
            cout << "Total Members: " << club1.count() << endl;
            break;
        case 6:
            cout << "Enter PRN to search: ";
            cin >> prn;
            club1.search(prn);
            break;
        case 7:
            cout << "Enter PRN to delete: ";
            cin >> prn;
            club1.deleteMember(prn);
            break;
        case 8:
            club1.reverse();
            break;
        case 9:
            club1.sortList();
            break;
        case 10:
            cout << "Add members in 2nd list first!" << endl;
            cout << "Enter PRN & Name for Secretary of list2: ";
            cin >> prn >> name;
            club2.addPresident(100, "TempPres"); // dummy president
            club2.addSecretary(prn, name);
            club1.concatenate(club2);
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice !=0);

    return 0;
}
