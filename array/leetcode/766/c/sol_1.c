/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 766. Toeplitz Matrix
 * @date 2021.05.17
 *
 * Time Complexity: O(m*n)
 * Space Complexity: O(1)
 * m is the number of rows
 * n is the number of cols
 */

#include <stdbool.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrix == NULL) {
        return false;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int x;
    int y;
    int value;
    int times;

    // detect each diagonal from [0,0] to [rows-1, 0]
    for (x = 0; x < rows; x++) {
        value = matrix[x][0];
        times = MIN(rows - x, cols);

        for (int i = 1; i < times; i++) {
            if (matrix[x + i][i] != value) {
                return false;
            }
        }
    }

    // detect each diagonal from [0,1] to [0, cols-1]
    for (y = 1; y < cols; y++) {
        value = matrix[0][y];
        times = MIN(rows, cols - y);

        for (int i = 1; i < times; i++) {
            if (matrix[i][y + i] != value) {
                return false;
            }
        }
    }

    return true;
}
