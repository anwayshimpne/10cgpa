#include <iostream>
using namespace std;

int main() {
    int rows, cols, terms;
    cout << "Enter number of rows, cols, and non-zero terms: ";
    cin >> rows >> cols >> terms;

    int sparse[terms][3];
    cout << "Enter Sparse Matrix (Row Col Value):\n";
    for (int i = 0; i < terms; i++) {
        cin >> sparse[i][0] >> sparse[i][1] >> sparse[i][2];
    }

    cout << "\nOriginal Sparse Matrix (Row Col Value):\n";
    for (int i = 0; i < terms; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }

    // Fast Transpose
    int fast[terms][3];
    int count[cols] = {0};    // count of elements in each column
    int index[cols];          // starting index for each column

    // Step 1: Count elements in each column of original
    for (int i = 0; i < terms; i++) {
        count[sparse[i][1]]++;
    }

    // Step 2: Starting index for each column in transposed
    index[0] = 0;
    for (int i = 1; i < cols; i++) {
        index[i] = index[i - 1] + count[i - 1];
    }

    // Step 3: Place elements directly in correct position
    for (int i = 0; i < terms; i++) {
        int col = sparse[i][1];
        int pos = index[col];
        fast[pos][0] = sparse[i][1]; // new row = old col
        fast[pos][1] = sparse[i][0]; // new col = old row
        fast[pos][2] = sparse[i][2]; // value stays
        index[col]++;
    }

    cout << "\nFast Transposed Sparse Matrix (Row Col Value):\n";
    for (int i = 0; i < terms; i++) {
        cout << fast[i][0] << " " << fast[i][1] << " " << fast[i][2] << endl;
    }

    return 0;
}
