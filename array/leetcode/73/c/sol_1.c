/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 73. Set Matrix Zeroes
 * @date 2021.05.12
 *
 * Time Complexity: O(m*n)
 * Space Complexity: O(1)
 * m is the number of rows
 * n is the number of cols
 */

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrix == NULL) {
        return;
    }

    bool clear_first_row = false;
    bool clear_first_col = false;

    // set clear first row flag if 0 in first row
    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            clear_first_row = true;
            break;
        }
    }

    // set clear first col flag if 0 in first col
    for (int i = 0; i < matrixColSize[0]; i++) {
        if (matrix[0][i] == 0) {
            clear_first_col = true;
            break;
        }
    }

    // set clear flag to first row or col
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // use flags in first row to clear matrix
    for (int i = 1; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < matrixColSize[0]; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // use flags in first col to clear matrix
    for (int i = 1; i < matrixColSize[0]; i++) {
        if (matrix[0][i] == 0) {
            for (int j = 1; j < matrixSize; j++) {
                matrix[j][i] = 0;
            }
        }
    }

    // clear first row
    if (clear_first_row) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }

    // clear first col
    if (clear_first_col) {
        for (int i = 0; i < matrixColSize[0]; i++) {
            matrix[0][i] = 0;
        }
    }
}
