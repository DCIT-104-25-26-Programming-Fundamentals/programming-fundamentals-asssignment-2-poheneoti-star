// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================



#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols);
void displayMatrix(int matrix[10][10], int rows, int cols);
void transposeMatrix(int matrix[10][10], int rows, int cols);
void addMatrices(int A[10][10], int B[10][10], int rows, int cols);
void multiplyMatrices(int A[10][10], int B[10][10], int rowsA, int colsA, int colsB);

int main()
{
    int choice;

    do
    {
        cout << "\n========== MATRIX OPERATIONS ==========\n";
        cout << "1. Transpose a Matrix\n";
        cout << "2. Add Two Matrices\n";
        cout << "3. Multiply Two Matrices\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int matrix[10][10];
            int rows, cols;

            cout << "Enter number of rows: ";
            cin >> rows;

            cout << "Enter number of columns: ";
            cin >> cols;

            cout << "\nEnter the matrix elements:\n";
            readMatrix(matrix, rows, cols);

            cout << "\nOriginal Matrix:\n";
            displayMatrix(matrix, rows, cols);

            cout << "\nTransposed Matrix:\n";
            transposeMatrix(matrix, rows, cols);
        }

        else if (choice == 2)
        {
            int A[10][10], B[10][10];
            int rows, cols;

            cout << "Enter number of rows: ";
            cin >> rows;

            cout << "Enter number of columns: ";
            cin >> cols;

            cout << "\nEnter Matrix A:\n";
            readMatrix(A, rows, cols);

            cout << "\nEnter Matrix B:\n";
            readMatrix(B, rows, cols);

            cout << "\nMatrix A:\n";
            displayMatrix(A, rows, cols);

            cout << "\nMatrix B:\n";
            displayMatrix(B, rows, cols);

            cout << "\nSum of Matrices:\n";
            addMatrices(A, B, rows, cols);
        }

        else if (choice == 3)
        {
            int A[10][10], B[10][10];
            int rowsA, colsA, rowsB, colsB;

            cout << "Enter rows of Matrix A: ";
            cin >> rowsA;

            cout << "Enter columns of Matrix A: ";
            cin >> colsA;

            cout << "Enter rows of Matrix B: ";
            cin >> rowsB;

            cout << "Enter columns of Matrix B: ";
            cin >> colsB;

            if (colsA != rowsB)
            {
                cout << "\nMatrix multiplication is not possible.\n";
                cout << "Columns of Matrix A must equal rows of Matrix B.\n";
            }
            else
            {
                cout << "\nEnter Matrix A:\n";
                readMatrix(A, rowsA, colsA);

                cout << "\nEnter Matrix B:\n";
                readMatrix(B, rowsB, colsB);

                cout << "\nMatrix A:\n";
                displayMatrix(A, rowsA, colsA);

                cout << "\nMatrix B:\n";
                displayMatrix(B, rowsB, colsB);

                cout << "\nProduct Matrix:\n";
                multiplyMatrices(A, B, rowsA, colsA, colsB);
            }
        }

        else if (choice == 4)
        {
            cout << "\nProgram ended.\n";
        }

        else
        {
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}

void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    displayMatrix(transpose, cols, rows);
}

void addMatrices(int A[10][10], int B[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    displayMatrix(sum, rows, cols);
}

void multiplyMatrices(int A[10][10], int B[10][10], int rowsA, int colsA, int colsB)
{
    int product[10][10];

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            product[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    displayMatrix(product, rowsA, colsB);
}

