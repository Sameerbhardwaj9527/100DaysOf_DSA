/*Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.



 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize,
                int* returnSize, int** returnColumnSizes) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    // Transpose matrix will have cols rows
    *returnSize = cols;

    // Allocate memory for column sizes
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    for (int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
    }

    // Allocate memory for transpose matrix
    int **result = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }

    // Transpose logic
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // Allocate memory for input matrix
    int **matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int *returnColumnSizes;

    // Call transpose function
    int **result = transpose(matrix, m, &n, &returnSize, &returnColumnSizes);

    // Print transposed matrix
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < m; i++)
        free(matrix[i]);
    free(matrix);

    for (int i = 0; i < returnSize; i++)
        free(result[i]);
    free(result);
    free(returnColumnSizes);

    return 0;
}
