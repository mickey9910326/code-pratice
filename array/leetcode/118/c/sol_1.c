/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 118. Pascal's Triangle
 * @date 2021.05.13
 *
 * Time Complexity: O(N) = O(r^2)
 * Space Complexity: O(N) = O(r^2)
 * N is num of cells
 * r is num of rows
 */

#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(sizeof(int*) * numRows);
    *returnColumnSizes = malloc(sizeof(int*) * numRows);

    for (int i = 0; i < numRows; i++) {
        result[i] = malloc(sizeof(int) * (i + 1));
        *returnColumnSizes[i] = i + 1;
    }

    if (numRows >= 1) {
        result[0][0] = 1;
    }

    if (numRows >= 2) {
        result[1][0] = 1;
        result[1][1] = 1;
    }

    for (int i = 2; i < numRows; i++) {
        result[i][0] = 1;
        result[i][i - 1] = 1;

        for (int j = 1; j < i - 1; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}
