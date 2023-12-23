#include <iostream>
#include <cstdlib>   // For rand() function
#include <ctime>     // For srand() function

using namespace std;

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to perform matrix multiplication
int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    // Check if matrices can be multiplied
    if (cols1 != rows2) {
        cerr << "Error: Incompatible matrix dimensions for multiplication." << endl;
        return nullptr;
    }

    // Initialize the result matrix with zeros
    int** result = new int*[rows1];
    for (int i = 0; i < rows1; ++i) {
        result[i] = new int[cols2];
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(nullptr)));

    // Define matrix dimensions
    const int rows1 = 100;
    const int cols1 = 100;
    const int rows2 = 100;
    const int cols2 = 100;

    // Create and fill matrices with random values
    int** matrix1 = new int*[rows1];
    for (int i = 0; i < rows1; ++i) {
        matrix1[i] = new int[cols1];
        for (int j = 0; j < cols1; ++j) {
            matrix1[i][j] = rand() % 10;  // Generates a random value between 0 and 9
        }
    }

    int** matrix2 = new int*[rows2];
    for (int i = 0; i < rows2; ++i) {
        matrix2[i] = new int[cols2];
        for (int j = 0; j < cols2; ++j) {
            matrix2[i][j] = rand() % 10;  // Generates a random value between 0 and 9
        }
    }

    // Print the matrices
    cout << "Matrix 1:" << endl;
    printMatrix(matrix1, rows1, cols1);

    cout << "Matrix 2:" << endl;
    printMatrix(matrix2, rows2, cols2);

    // Perform matrix multiplication
    int** result = multiplyMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);

    // Print the result matrix
    if (result != nullptr) {
        cout << "Result Matrix:" << endl;
        printMatrix(result, rows1, cols2);

        // Clean up memory
        for (int i = 0; i < rows1; ++i) {
            delete[] matrix1[i];
        }
        delete[] matrix1;

        for (int i = 0; i < rows2; ++i) {
            delete[] matrix2[i];
        }
        delete[] matrix2;

        for (int i = 0; i < rows1; ++i) {
            delete[] result[i];
        }
        delete[] result;
    }

    return 0;
}
