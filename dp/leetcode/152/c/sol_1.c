/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 152. Maximum Product Subarray
 * @date 2021.01.29
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdint.h>

#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x < y) ? x : y)

// get maximum or minimum of 3 elements
#define MAX_3E(x, y, z) (MAX(x, MAX(y, z)))
#define MIN_3E(x, y, z) (MIN(x, MIN(y, z)))

int maxProduct(int* nums, int numsSize) {
    int max = 1;
    int min = 1;
    int tmp = 1;
    int res = INT32_MIN;

    for (int i = 0; i < numsSize; i++) {
        tmp = max * nums[i];
        max = MAX_3E(nums[i], max * nums[i], min * nums[i]);
        min = MIN_3E(nums[i], min * nums[i], tmp);
        res = MAX(res, max);
    }

    return res;
}
