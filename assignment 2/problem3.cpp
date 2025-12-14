#include <iostream>
#include <vector>
using namespace std;

// ------------------- Custom Swap -------------------
void mySwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// ------------------- Partition Function -------------------
int partition(vector<int> &arr, int st, int end) {
    int pivot = arr[end];
    int idx = st - 1;

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            mySwap(arr[idx], arr[j]);
        }
    }
    mySwap(arr[idx + 1], arr[end]);
    return idx + 1;
}

// ------------------- Quick Sort -------------------
void quickSort(vector<int> &arr, int st, int end, int pass) {
    if (st < end) {
        int pivIdx = partition(arr, st, end);

        // Print pass analysis
        cout << "Pass " << pass << ": ";
        for (int val : arr) cout << val << " ";
        cout << endl;

        quickSort(arr, st, pivIdx - 1, pass + 1);   // left side
        quickSort(arr, pivIdx + 1, end, pass + 1);  // right side
    }
}

// ------------------- Divide & Conquer for Min/Max -------------------
void findMinMax(vector<int> &arr, int low, int high, int &minVal, int &maxVal) {
    // Base Case: One element
    if (low == high) {
        minVal = maxVal = arr[low];
        return;
    }
    // Base Case: Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minVal = arr[low];
            maxVal = arr[high];
        } else {
            minVal = arr[high];
            maxVal = arr[low];
        }
        return;
    }

    // Divide
    int mid = (low + high) / 2;
    int min1, max1, min2, max2;

    // Recurse left and right halves
    findMinMax(arr, low, mid, min1, max1);
    findMinMax(arr, mid + 1, high, min2, max2);

    // Conquer (combine results)
    minVal = (min1 < min2) ? min1 : min2;
    maxVal = (max1 > max2) ? max1 : max2;
}

// ------------------- MAIN -------------------
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    // Quick Sort with pass-by-pass analysis
    cout << "\nSorting process (Quick Sort):\n";
    quickSort(marks, 0, n - 1, 1);

    cout << "\nSorted Marks (Ascending): ";
    for (int m : marks) cout << m << " ";
    cout << endl;

    // Find Min & Max using Divide and Conquer
    int minVal, maxVal;
    findMinMax(marks, 0, n - 1, minVal, maxVal);

    cout << "\nMinimum Marks: " << minVal;
    cout << "\nMaximum Marks: " << maxVal << endl;

    return 0;
}
