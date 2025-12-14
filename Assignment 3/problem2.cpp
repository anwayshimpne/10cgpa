#include <iostream>
using namespace std;

struct Seat {
    int seatNo;
    bool booked;
    Seat* next;
    Seat* prev;
};

class GalaxyMultiplex {
    Seat* rows[8];   // Array of 8 head pointers (one for each row)

public:
    GalaxyMultiplex() {
        // Initialize rows with 8 circular doubly linked seats each
        for (int i = 0; i < 8; i++) {
            rows[i] = NULL;
            createRow(i);
        }
    }

    void createRow(int row) {
        Seat* head = NULL;
        Seat* last = NULL;

        for (int i = 1; i <= 8; i++) {
            Seat* newSeat = new Seat();
            newSeat->seatNo = i;
            newSeat->booked = (rand() % 2);  // randomly book some seats
            newSeat->next = newSeat->prev = NULL;

            if (!head) {
                head = newSeat;
                last = newSeat;
            } else {
                last->next = newSeat;
                newSeat->prev = last;
                last = newSeat;
            }
        }
        // make circular
        head->prev = last;
        last->next = head;
        rows[row] = head;
    }

    // a) Display current seat availability
    void display() {
        cout << "\nGalaxy Multiplex Seat Availability (0 = Free, 1 = Booked)\n";
        for (int i = 0; i < 8; i++) {
            cout << "Row " << i + 1 << ": ";
            Seat* temp = rows[i];
            do {
                cout << "[" << temp->seatNo << ":" << (temp->booked ? "X" : "O") << "] ";
                temp = temp->next;
            } while (temp != rows[i]);
            cout << endl;
        }
    }

    // b) Book seat(s)
    void bookSeat(int row, int seatNo) {
        if (row < 1 || row > 8 || seatNo < 1 || seatNo > 8) {
            cout << "Invalid seat/row!\n";
            return;
        }
        Seat* temp = rows[row - 1];
        do {
            if (temp->seatNo == seatNo) {
                if (!temp->booked) {
                    temp->booked = true;
                    cout << "Seat " << seatNo << " in Row " << row << " booked successfully!\n";
                } else {
                    cout << "Seat already booked!\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != rows[row - 1]);
    }

    // c) Cancel booking
    void cancelSeat(int row, int seatNo) {
        if (row < 1 || row > 8 || seatNo < 1 || seatNo > 8) {
            cout << "Invalid seat/row!\n";
            return;
        }
        Seat* temp = rows[row - 1];
        do {
            if (temp->seatNo == seatNo) {
                if (temp->booked) {
                    temp->booked = false;
                    cout << "Seat " << seatNo << " in Row " << row << " cancelled successfully!\n";
                } else {
                    cout << "Seat is not booked yet!\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != rows[row - 1]);
    }
};

int main() {
    GalaxyMultiplex g;

    g.display();

    g.bookSeat(5, 2);     // book row 5 seat 2
    g.bookSeat(5, 2);     // try booking again (error)

    g.display();

    g.cancelSeat(2, 5);   // cancel booking
    g.cancelSeat(2, 5);   // try cancelling again (error)

    g.display();

    return 0;
}
