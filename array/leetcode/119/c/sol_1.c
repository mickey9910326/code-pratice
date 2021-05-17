/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 119. Pascal's Triangle II
 * @date 2021.05.17
 *
 * Time Complexity: O(N) = O(r^2)
 * Space Complexity: O(N) = O(r^2)
 * N is num of cells
 * r is num of rows
 */

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int* result = malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;

    for (int i = 0; i < rowIndex + 1; i++) {
        result[i] = 1;
    }

    for (int i = 1; i < rowIndex; i++) {
        for (int j = i; j >= 1; j--) {
            result[j] = result[j] + result[j - 1];
        }
    }

    return result;
}
