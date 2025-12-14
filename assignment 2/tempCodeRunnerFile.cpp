#include <iostream>
using namespace std;

struct Student {
    string name;
    int marks;
    int rollNo;
};


void mySwap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

// Bubble Sort (Descending order with pass analysis)
void bubbleSort(Student arr[], int n) {
    for (int pass = 1; pass < n; pass++) {
        
        for (int j = 0; j < n - pass; j++) {
            if (arr[j].marks < arr[j + 1].marks) {
                mySwap(arr[j], arr[j + 1]);
                
            }
        }

        // Pass
        cout << "Pass " << pass << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k].marks << " ";
        }
        cout << endl;

        
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[100]; 

    cout << "Enter name and marks of each student:\n";
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].marks;
    }

    
    bubbleSort(students, n);

    // Assign roll numbers
    for (int i = 0; i < n; i++) {
        students[i].rollNo = i + 1; // topper gets roll no 1
    }

    // Display final result
    cout << "\nFinal Roll Numbers (based on marks):\n";
    for (int i = 0; i < n; i++) {
        cout << "Roll No. " << students[i].rollNo
             << " -> " << students[i].name
             << " (" << students[i].marks << " marks)\n";
    }

    return 0;
}
