import java.util.Random;

public class MatrixMultiplication {
    public static void main(String[] args) {
        // Set the dimensions of the matrices
        int rowsA = 100;
        int colsA = 100;
        int rowsB = 100;
        int colsB = 100;

        // Create two random matrices
        int[][] matrixA = generateRandomMatrix(rowsA, colsA);
        int[][] matrixB = generateRandomMatrix(rowsB, colsB);

        // Multiply the matrices
        long startTime = System.currentTimeMillis();
        int[][] resultMatrix = multiplyMatrices(matrixA, matrixB);
        long endTime = System.currentTimeMillis();

        // Display the time taken for multiplication
        System.out.println("Matrix multiplication took " + (endTime - startTime) + " milliseconds.");

        // You can uncomment the following lines to print the matrices and the result
        // printMatrix(matrixA);
        // printMatrix(matrixB);
        // printMatrix(resultMatrix);
    }

    // Function to generate a random matrix with given dimensions
    private static int[][] generateRandomMatrix(int rows, int cols) {
        int[][] matrix = new int[rows][cols];
        Random random = new Random();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = random.nextInt(10); // Adjust the range of random values as needed
            }
        }

        return matrix;
    }

    // Function to multiply two matrices
    private static int[][] multiplyMatrices(int[][] matrixA, int[][] matrixB) {
        int rowsA = matrixA.length;
        int colsA = matrixA[0].length;
        int colsB = matrixB[0].length;

        int[][] resultMatrix = new int[rowsA][colsB];

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }

        return resultMatrix;
    }
}
