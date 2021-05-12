/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 66. Plus One
 * @date 2021.05.13
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * n is the number of cols
 */

#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // detect to increase digits size or not
    // if all value is 9
    int increase_size = 1;
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9) {
            increase_size = 0;
            break;
        }
    }

    int size = digitsSize + increase_size;
    *returnSize = size;
    int* result = malloc(sizeof(int) * size);
    int carry = 1;

    result[0] = 0;

    for (int i = 0; i < digitsSize; i++) {
        result[i + increase_size] = digits[i];
    }

    // do carry
    for (int i = size - 1; i >= 0 && carry; i--) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }

    return result;
}
