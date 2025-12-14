#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int start_time;   // appointment start time (in 24-hour format, e.g. 9 means 9:00)
    int end_time;     // appointment end time
    bool booked;      // true if slot is booked
    string name;      // person who booked
    Node* next;

    Node(int start, int end) {
        start_time = start;
        end_time = end;
        booked = false;
        name = "";
        next = NULL;
    }
};

class AppointmentSchedule {
    Node* head;
    int min_duration;
    int max_duration;

public:
    AppointmentSchedule(int start_day, int end_day, int min_dur, int max_dur) {
        head = NULL;
        min_duration = min_dur;
        max_duration = max_dur;

        // Create appointment slots dynamically (1-hour slots)
        for (int time = start_day; time < end_day; time++) {
            insertSlot(time, time + 1);
        }
    }

    void insertSlot(int start, int end) {
        Node* newNode = new Node(start, end);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void displaySlots() {
        Node* temp = head;
        cout << "\n------ APPOINTMENT SLOTS ------\n";
        cout << "Time Slot\tStatus\t\tName\n";
        while (temp) {
            cout << temp->start_time << ":00 - " << temp->end_time << ":00\t";
            if (temp->booked)
                cout << "BOOKED\t\t" << temp->name << "\n";
            else
                cout << "AVAILABLE\t-\n";
            temp = temp->next;
        }
    }

    void bookAppointment(string person, int start, int end) {
        if (end - start < min_duration || end - start > max_duration) {
            cout << " Appointment duration not within allowed limits ("
                 << min_duration << "-" << max_duration << " hour(s)).\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            if (temp->start_time == start && temp->end_time == end) {
                if (temp->booked) {
                    cout << " Slot already booked by " << temp->name << ".\n";
                    return;
                } else {
                    temp->booked = true;
                    temp->name = person;
                    cout << "✅ Appointment booked successfully for " << person << " at "
                         << start << ":00 - " << end << ":00.\n";
                    return;
                }
            }
            temp = temp->next;
        }
        cout << " Invalid time slot.\n";
    }

    void cancelAppointment(string person, int start, int end) {
        Node* temp = head;
        while (temp) {
            if (temp->start_time == start && temp->end_time == end) {
                if (!temp->booked) {
                    cout << " No appointment found in this slot.\n";
                    return;
                }
                if (temp->name != person) {
                    cout << " Appointment belongs to " << temp->name << ", not " << person << ".\n";
                    return;
                }
                temp->booked = false;
                temp->name = "";
                cout << "✅ Appointment cancelled successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << " Invalid slot entered.\n";
    }

    // Sort the list by swapping data (normal method)
    void sortByTime() {
        if (!head || !head->next)
            return;

        for (Node* i = head; i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->start_time > j->start_time) {
                    // swap data (not pointers)
                    swap(i->start_time, j->start_time);
                    swap(i->end_time, j->end_time);
                    swap(i->booked, j->booked);
                    swap(i->name, j->name);
                }
            }
        }
        cout << " Appointments sorted by time (data swapped).\n";
    }

    // Sort using pointer manipulation (no data swapping)
    void sortByPointer() {
        if (!head || !head->next)
            return;

        bool swapped;
        do {
            swapped = false;
            Node** ptr = &head;
            Node* a = head;
            Node* b = head->next;

            while (b) {
                if (a->start_time > b->start_time) {
                    a->next = b->next;
                    b->next = a;
                    *ptr = b;
                    swapped = true;
                }
                ptr = &(a->next);
                a = *ptr;
                if (a)
                    b = a->next;
                else
                    break;
            }
        } while (swapped);

        cout << " Appointments sorted using pointer manipulation.\n";
    }
};

// ============================ MAIN FUNCTION =============================

int main() {
    int start_day = 9, end_day = 17; // 9 AM to 5 PM
    int min_dur = 1, max_dur = 2;

    AppointmentSchedule schedule(start_day, end_day, min_dur, max_dur);
    int choice;
    string name;
    int start, end;

    cout << "==============================\n";
    cout << "  APPOINTMENT SCHEDULING SYSTEM\n";
    cout << "==============================\n";

    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. Display available slots\n";
        cout << "2. Book new appointment\n";
        cout << "3. Cancel appointment\n";
        cout << "4. Sort appointments (by data swap)\n";
        cout << "5. Sort appointments (by pointer manipulation)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            schedule.displaySlots();
            break;
        case 2:
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter start time (e.g. 9 for 9:00): ";
            cin >> start;
            cout << "Enter end time (e.g. 10 for 10:00): ";
            cin >> end;
            schedule.bookAppointment(name, start, end);
            break;
        case 3:
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter start time of appointment to cancel: ";
            cin >> start;
            cout << "Enter end time of appointment to cancel: ";
            cin >> end;
            schedule.cancelAppointment(name, start, end);
            break;
        case 4:
            schedule.sortByTime();
            break;
        case 5:
            schedule.sortByPointer();
            break;
        case 6:
            cout << "Exiting system. Thank you!\n";
            return 0;
        default:
            cout << " Invalid choice. Try again.\n";
        }
    }
}
