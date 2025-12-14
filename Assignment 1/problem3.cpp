#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> mat;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(rows, vector<int>(cols, 0));
    }

    void inputMatrix() {
        cout << "Enter elements (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> mat[i][j];
    }

    void displayMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << "\t";
            cout << "\n";
        }
    }

    Matrix multiplyRowMajor(const Matrix &B) {
        Matrix result(rows, B.cols);

        auto start = high_resolution_clock::now();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < B.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.mat[i][j] += mat[i][k] * B.mat[k][j];
        auto end = high_resolution_clock::now();

        cout << "\nRow-Major Multiplication Time: "
             << duration_cast<milliseconds>(end - start).count()
             << " ms\n";

        return result;
    }

    Matrix multiplyColumnMajor(const Matrix &B) {
        Matrix result(rows, B.cols);

        auto start = high_resolution_clock::now();
        // Notice the different loop order: this simulates column-major access
        for (int j = 0; j < B.cols; j++)
            for (int k = 0; k < cols; k++)
                for (int i = 0; i < rows; i++)
                    result.mat[i][j] += mat[i][k] * B.mat[k][j];
        auto end = high_resolution_clock::now();

        cout << "\nColumn-Major Multiplication Time: "
             << duration_cast<milliseconds>(end - start).count()
             << " ms\n";

        return result;
    }
};

// Menu-driven driver code
int main() {
    int r1, c1, r2, c2, choice;
    cout << "=== MATRIX MULTIPLICATION & CACHE PERFORMANCE ANALYSIS ===\n";

    cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible! (c1 != r2)\n";
        return 0;
    }

    Matrix A(r1, c1), B(r2, c2), C(r1, c2);
    cout << "\nEnter elements for Matrix A:\n";
    A.inputMatrix();
    cout << "\nEnter elements for Matrix B:\n";
    B.inputMatrix();

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Display Matrix A\n";
        cout << "2. Display Matrix B\n";
        cout << "3. Multiply (Row-Major Order)\n";
        cout << "4. Multiply (Column-Major Order)\n";
        cout << "5. Compare Both\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nMatrix A:\n";
            A.displayMatrix();
            break;
        case 2:
            cout << "\nMatrix B:\n";
            B.displayMatrix();
            break;
        case 3:
            cout << "\nResult (Row-Major Order):\n";
            C = A.multiplyRowMajor(B);
            C.displayMatrix();
            break;
        case 4:
            cout << "\nResult (Column-Major Order):\n";
            C = A.multiplyColumnMajor(B);
            C.displayMatrix();
            break;
        case 5: {
            cout << "\n--- Comparing Cache Performance ---\n";
            A.multiplyRowMajor(B);
            A.multiplyColumnMajor(B);
            cout << "Observe which access pattern performs faster.\n";
            break;
        }
        case 6:
            cout << "Exiting... Thank you!\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
