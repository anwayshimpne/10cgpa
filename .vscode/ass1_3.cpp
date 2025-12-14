#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
const int N =2000;   // Matrix size (N x N)

// Function for Row-Major Multiplication
void rowMajorMultiply(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {             // row of A
        for (int j = 0; j < N; j++) {         // col of B
            int sum = 0;
            for (int k = 0; k < N; k++) {     // row-major friendly
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

// Function for Column-Major Multiplication
void columnMajorMultiply(int A[N][N], int B[N][N], int C[N][N]) {
    for (int j = 0; j < N; j++) {             // col of B first (cache unfriendly)
        for (int i = 0; i < N; i++) {         // row of A
            int sum = 0;
            for (int k = 0; k < N; k++) {     // column-major access
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    static int A[N][N], B[N][N], C[N][N]; // static → avoids stack overflow

    // Initialize matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 2;
            C[i][j] = 0;
        }
    }

    // Row-Major Performance
    auto start1 = high_resolution_clock::now();
    rowMajorMultiply(A, B, C);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Row-Major Multiplication Time: " << duration1.count() << " ms\n";

    // Column-Major Performance
    auto start2 = high_resolution_clock::now();
    columnMajorMultiply(A, B, C);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "Column-Major Multiplication Time: " << duration2.count() << " ms\n";

    return 0;
}
