/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 885. Spiral Matrix III
 * @date 2021.05.13
 *
 * Time Complexity: O(MAX(m^2, n^2))
 * Space Complexity: O(m*n)
 * m is num of rows
 * n is num of cols
 */

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** spiralMatrixIII(int rows, int cols, int rStart, int cStart,
                      int* returnSize, int** returnColumnSizes) {
    // memory allocating
    int** result = malloc(sizeof(int*) * rows * cols);
    *returnSize = rows * cols;
    *returnColumnSizes = malloc(sizeof(int) * rows * cols);
    for (int i = 0; i < rows * cols; i++) {
        result[i] = malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }

    int idx = 0;
    int x = rStart;
    int y = cStart - 1;

    const int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int move_idx = 0;
    int padding = 1;

    while (idx < rows * cols) {
        x += move[move_idx][0];
        y += move[move_idx][1];

        // if exceed square boundary, rollback and change move way.
        if ((x < rStart - padding) || (x > rStart + padding) ||
            (y < cStart - padding) || (y > cStart + padding)) {
            x -= move[move_idx][0];
            y -= move[move_idx][1];
            move_idx++;
            continue;
        }

        // printf("idx %d: (%2d,%2d)", idx, x, y);

        // if meets in matrix, put value to it
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            // printf(" meets matrix");
            result[idx][0] = x;
            result[idx][1] = y;
            idx++;
        }
        // printf("\n");

        if ((x == rStart - padding) && (y == cStart - padding) &&
            move_idx == 3) {
            // printf("finish a cycle\n");
            // finish a cycle
            padding++;
            move_idx = 0;
        }
    }
    return result;
}
