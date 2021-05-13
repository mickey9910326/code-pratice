/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 54. Spiral Matrix
 * @date 2021.05.13
 *
 * Time Complexity: O(m*n)
 * Space Complexity: O(1)
 * m is num of rows
 * n is num of cols
 */

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize,
                 int* returnSize) {
    int row_size = matrixSize;
    int col_size = matrixColSize[0];

    int* result = malloc(sizeof(int) * row_size * col_size);
    *returnSize = row_size * col_size;

    int idx = 0;
    int x = 0;
    int y = -1;

    const int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int move_idx = 0;
    int padding = 0;

    while (idx < row_size * col_size) {
        x += move[move_idx][0];
        y += move[move_idx][1];

        // if exceed boundary, rollback and change move way.
        if ((x < padding) || (x >= row_size - padding) || (y < padding) ||
            (y >= col_size - padding)) {
            x -= move[move_idx][0];
            y -= move[move_idx][1];
            move_idx++;
            continue;
        }
        // printf("idx %d: (%d,%d), value: %d\n",idx,x,y, matrix[x][y]);

        result[idx] = matrix[x][y];
        idx++;

        if (x == padding + 1 && y == padding && move_idx == 3) {
            // printf("finish a cycle\n");
            // finish a cycle
            padding++;
            move_idx = 0;
        }
    }
    return result;
}
