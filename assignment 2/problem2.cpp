#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Student {
    string name;
    int rollNo;
    float marks;
};

//  Bubble Sort
int bubbleSort(vector<Student> &arr) {
    int n = arr.size();
    int swapCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].rollNo > arr[j + 1].rollNo) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

// Quick Sort 
int quickSortSwaps = 0;

// Partition function
int partition(vector<Student> &arr, int st, int end) {
    int pivot = arr[end].rollNo;
    int idx = st - 1;

    for (int j = st; j < end; j++) {
        if (arr[j].rollNo <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
            quickSortSwaps++;
        }
    }

    swap(arr[end], arr[idx + 1]);
    quickSortSwaps++;
    return idx + 1;
}

void quickSort(vector<Student> &arr, int st, int end) {
    if (st < end) {
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx - 1);  //call quicksort for left side
        quickSort(arr, pivIdx + 1, end);   //call quicksort forYashraj 17 92

    }
}


void display(const vector<Student> &arr) {
    cout << "\nRollNo\tName\t\tMarks\n";
    for (auto s : arr) {
        cout << s.rollNo << "\t" << s.name << "\t\t" << s.marks << endl;
    }
}


int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> arr1(n), arr2(n);

    cout << "Enter student details (Name RollNo Marks):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i].name >> arr1[i].rollNo >> arr1[i].marks;
        arr2[i] = arr1[i]; // copy for quicksort
    }

    // Bubble Sort
    int bubbleSwaps = bubbleSort(arr1);
    cout << "\nAfter Bubble Sort (by RollNo):";
    display(arr1);
    cout << "Total swaps in Bubble Sort = "<<bubbleSwaps<<endl;

    // Quick Sort
    quickSort(arr2, 0, n - 1);
    cout << "\nAfter Quick Sort (by RollNo):";
    display(arr2);
    cout <<"Total swaps in Quick Sort = "<<quickSortSwaps<<endl;

    return 0;
}
