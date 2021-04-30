/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1237. Find Positive Integer Solution for a Given Equation
 * @date 2020.12.10
 *
 * Time Complexity: O(n)
 */

#include <stdlib.h>

/*
 * // This is the definition for customFunction API.
 * // You should not implement it, or speculate about its implementation
 *
 * // Returns f(x, y) for any given positive integers x and y.
 * // Note that f(x, y) is increasing with respect to both x and y.
 * // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** findSolution(int (*customFunction)(int, int), int z, int* returnSize,
                   int** returnColumnSizes) {
    // Max num of (x, y) fit f(x, y) = z is 1000.
    // Because f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1).
    int** sols = (int**)malloc(sizeof(int*) * 1000);

    // record count of solutions.
    int count = 0;

    // record each size of item sol(int*) of "sols".
    int* colSizes = (int*)malloc(sizeof(int) * 1000);

    int x = 1;
    int y = 1000;

    while (x <= 1000 && y >= 1) {
        if (customFunction(x, y) == z) {
            colSizes[count] = 2;

            sols[count] = malloc(sizeof(int) * 2);
            sols[count][0] = x;
            sols[count][1] = y;

            count++;
            x++;
        }
        else if (customFunction(x, y) < z) {
            x++;
        }
        else {
            y--;
        }
    }

    *returnSize = count;
    *returnColumnSizes = colSizes;

    return sols;
}
