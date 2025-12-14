#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    string name;
    double height;
    double weight;
    double avg;

    Employee(string n, double h, double w) {
        name = n;
        height = h;
        weight = w;
        avg = (h + w) / 2.0;
    }
};

// ---------- Merge Sort ----------
void merge(vector<Employee>& arr, int st, int mid, int end) {
    vector<Employee> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i].avg <= arr[j].avg) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);

    for (int k = 0; k < (int)temp.size(); k++) {
        arr[st + k] = temp[k];
    }
}

void mergeSort(vector<Employee>& arr, int st, int end) {
    if (st >= end) return;
    int mid = st + (end - st) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, st, mid, end);
}

// ---------- Selection Sort ----------
void selectionSort(vector<Employee>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].avg < arr[min_idx].avg) {
                min_idx = j;
            }
        }
        if (min_idx != i) swap(arr[i], arr[min_idx]);
    }
}

// ---------- Display ----------
void printEmployees(const vector<Employee>& v) {
    cout << "\nSorted Employees (by average of height & weight):\n";
    cout << "-------------------------------------------------\n";
    for (const auto& e : v) {
        cout << "Name: " << e.name 
             << "\t | Height: " << e.height 
             << "\t | Weight: " << e.weight 
             << "\t | Avg: " << e.avg << "\n";
    }
    cout << "-------------------------------------------------\n";
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    vector<Employee> employees;
    for (int i = 0; i < n; i++) {
        string name;
        double h, w;
        cout << "Enter name, height and weight of employee " << (i+1) << ": ";
        cin >> name >> h >> w;
        employees.push_back(Employee(name, h, w));
    }

    while (true) {
        cout << "\n=== Sorting Menu ===\n";
        cout << "1. Merge Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            vector<Employee> temp = employees; // copy original
            mergeSort(temp, 0, n - 1);
            cout << "\n--- Sorted using Merge Sort ---\n";
            printEmployees(temp);
        } 
        else if (choice == 2) {
            vector<Employee> temp = employees; // copy original
            selectionSort(temp);
            cout << "\n--- Sorted using Selection Sort ---\n";
            printEmployees(temp);
        } 
        else if (choice == 3) {
            cout << "Exiting program. Thank you!\n";
            break;
        } 
        else {
            cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}
