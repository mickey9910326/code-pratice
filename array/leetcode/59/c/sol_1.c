/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 59. Spiral Matrix II
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
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int row_size = n;
    int col_size = n;

    int** result = malloc(sizeof(int*) * row_size);
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * row_size);
    for (int i = 0; i < n; i++) {
        result[i] = malloc(sizeof(int) * col_size);
        (*returnColumnSizes)[i] = n;
    }

    int idx = 0;
    int value = 1;
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
        // printf("idx %d: (%d,%d), value: %d\n",idx,x,y, value);

        result[x][y] = value;
        idx++;
        value++;

        if (x == padding + 1 && y == padding && move_idx == 3) {
            // printf("finish a cycle\n");
            // finish a cycle
            padding++;
            move_idx = 0;
        }
    }
    return result;
}
