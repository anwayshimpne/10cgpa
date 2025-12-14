
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of cols: ";
    cin >> cols;

    int normal[50][50];
    cout << "\nEnter matrix values:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> normal[i][j];
        }
    }

    // Display normal matrix
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << normal[i][j] << " ";
        }
        cout << endl;
    }

    // Convert to sparse matrix
    int sparse[100][3]; // First row is header
    int k = 1; // Start filling from index 1

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (normal[i][j] != 0) {
                sparse[k][0] = i;        // row
                sparse[k][1] = j;        // col
                sparse[k][2] = normal[i][j]; // value
                k++;
            }
        }
    }

    // Store header row [rows cols nonZeroCount]
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;

    // Display sparse matrix
    cout << "\nSparse Matrix (Row Col Value):\n";
    for (int i = 0; i < k; i++) {
        cout << sparse[i][0] << " " 
             << sparse[i][1] << " " 
             << sparse[i][2] << endl;
    }

    // Simple transpose
    cout << "\nSimple Transpose (Row Col Value):\n";
    cout << sparse[0][1] << " " 
         << sparse[0][0] << " " 
         << sparse[0][2] << endl;

    for (int i = 1; i < k; i++) {
        cout << sparse[i][1] << " "   // swap row & col
             << sparse[i][0] << " " 
             << sparse[i][2] << endl;
    }

    return 0;
}
