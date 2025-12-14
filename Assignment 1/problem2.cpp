#include <iostream>
#include <iomanip>
using namespace std;

// Function to print the square
void printSquare(int n, int square[50][50]) {
    cout << "\nMagic Square of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << square[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Odd order magic square (Siamese method)
void generateOddMagicSquare(int n, int square[50][50]) {
    // Initialize with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = 0;

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n; num++) {
        square[i][j] = num;

        i--; j++;

        if (i == -1 && j == n) { i = 0; j = n - 2; }
        if (i < 0) i = n - 1;
        if (j == n) j = 0;
        if (square[i][j] != 0) { i += 1; j -= 2; }
    }
}

// Even order magic square (doubly even method)
void generateEvenMagicSquare(int n, int square[50][50]) {
    // Works only for doubly even (n % 4 == 0)
    int num = 1;
    int num2 = n * n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i % 4 == j % 4) || ((i + j) % 4 == 3))
                square[i][j] = num2;
            else
                square[i][j] = num;
            num++;
            num2--;
        }
    }
}

int main() {
    int n, choice;
    int square[50][50];

    cout << "      MAGIC SQUARE PROGRAM     \n";
    cout << "-------------------------------\n";

menu:
    cout << "Menu:\n";
    cout << " 1. Generate Magic Square (Odd n)\n";
    cout << " 2. Generate Magic Square (Even n-->doubly even)\n";
    cout << " 3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter odd order (n): ";
            cin >> n;
            if (n % 2 == 0) {
                cout << "Please enter an odd value of n.\n";
            } else {
                generateOddMagicSquare(n, square);
                printSquare(n, square);
            }
            break;

        case 2:
            cout << "Enter even order (n): ";
            cin >> n;
            if (n % 4 != 0) {
                cout << "Please enter doubly even n (n % 4 == 0).\n";
            } else {
                generateEvenMagicSquare(n, square);
                printSquare(n, square);
            }
            break;

        case 3:
            cout << "Exiting program. Thank you!\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
    }
    goto menu;
}
