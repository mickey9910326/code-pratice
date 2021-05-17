/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 766. Toeplitz Matrix
 * @date 2021.05.17
 *
 * Simpler logic.
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

    for (int x = 1; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            if (matrix[x][y] != matrix[x - 1][y - 1]) {
                return false;
            }
        }
    }

    return true;
}
