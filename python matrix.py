import numpy as np
import time

def generate_random_matrix(rows, cols):
    return np.random.randint(10, size=(rows, cols))

def multiply_matrices(matrixA, matrixB):
    return np.dot(matrixA, matrixB)

def main():
    # Set the dimensions of the matrices
    rowsA, colsA = 500, 500
    rowsB, colsB = 500, 500

    # Create two random matrices
    matrixA = generate_random_matrix(rowsA, colsA)
    matrixB = generate_random_matrix(rowsB, colsB)

    # Multiply the matrices
    start_time = time.time()
    result_matrix = multiply_matrices(matrixA, matrixB)
    end_time = time.time()

    # Display the time taken for multiplication
    print(f"Matrix multiplication took {end_time - start_time:.4f} seconds.")

    # You can uncomment the following lines to print the matrices and the result
    # print("Matrix A:")
    # print(matrixA)
    # print("\nMatrix B:")
    # print(matrixB)
    # print("\nResult Matrix:")
    # print(result_matrix)

if _name_ == "_main_":
    main()