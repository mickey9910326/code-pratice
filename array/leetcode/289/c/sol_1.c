/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 289. Game of Life
 * @date 2021.05.12
 *
 * Time Complexity: O(m*n)
 * Space Complexity: O(1)
 * m is the number of rows
 * n is the number of cols
 */

#include <stdlib.h>

void gameOfLife(int** board, int boardSize, int* boardColSize) {
    if (board == NULL) {
        return;
    }

    int row_size = boardSize;
    int col_size = boardColSize[0];

    const int move[2][8] = {
        {-1, -1}, {+0, -1}, {+1, -1}, {-1, +0},
        {+1, +0}, {-1, +1}, {+0, +1}, {+1, +1},
    };

    int x, y;
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (board[i][j] & 1) {
                for (int k = 0; k < 8; k++) {
                    x = i + move[0][k];
                    y = j + move[1][k];
                    if (x >= 0 && x < row_size && y >= 0 && y < col_size) {
                        board[x][y] += 1 << 1;
                    }
                }
            }
        }
    }
    int num_of_lives;
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            num_of_lives = board[i][j] >> 1;
            if (board[i][j] & 1) {
                if (num_of_lives == 2 || num_of_lives == 3) {
                    // 2. Any live cell with two or three live neighbors lives
                    // on to the next generation.
                    board[i][j] = 1;
                }
                else {
                    // 1. Any live cell with fewer than two live neighbors dies
                    // as if caused by under-population.
                    // 3. Any live cell with more than three live neighbors
                    // dies, as if by over-population.
                    board[i][j] = 0;
                }
            }
            else {
                if (num_of_lives == 3) {
                    board[i][j] = 1;
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
}
