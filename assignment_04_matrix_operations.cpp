#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// -----------------------------------------------------------------------------
// Helper: read a matrix from the user
// -----------------------------------------------------------------------------
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string name) {
    cout << "Enter values for matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// Helper: display a matrix neatly using setw()
// -----------------------------------------------------------------------------
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum = sum + a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------
int main() {
    int rows, cols;

    // ---------------- PART A: Transpose ----------------
    cout << "===== PART A: TRANSPOSE =====" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrixA[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];

    readMatrix(matrixA, rows, cols, "A");
    transposeMatrix(matrixA, rows, cols, transposed);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrixA, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);

    // ---------------- PART B: Addition ----------------
    cout << "\n===== PART B: MATRIX ADDITION =====" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int addA[MAX_SIZE][MAX_SIZE];
    int addB[MAX_SIZE][MAX_SIZE];
    int sumResult[MAX_SIZE][MAX_SIZE];

    readMatrix(addA, rows, cols, "A");
    readMatrix(addB, rows, cols, "B");
    addMatrices(addA, addB, rows, cols, sumResult);

    cout << "\nSum of Matrices:" << endl;
    printMatrix(sumResult, rows, cols);

    // ---------------- PART C: Multiplication ----------------
    cout << "\n===== PART C: MATRIX MULTIPLICATION =====" << endl;
    int m, n, p;

    cout << "Enter rows of A (M): ";
    cin >> m;
    cout << "Enter columns of A / rows of B (N): ";
    cin >> n;
    cout << "Enter columns of B (P): ";
    cin >> p;

    int mulA[MAX_SIZE][MAX_SIZE];
    int mulB[MAX_SIZE][MAX_SIZE];
    int productResult[MAX_SIZE][MAX_SIZE];

    readMatrix(mulA, m, n, "A");
    readMatrix(mulB, n, p, "B");
    multiplyMatrices(mulA, mulB, m, n, p, productResult);

    cout << "\nProduct Matrix (A x B):" << endl;
    printMatrix(productResult, m, p);

    return 0;
}