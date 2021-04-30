/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 53. Maximum Subarray
 * @date 2021.01.29
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdint.h>

#define MAX(x, y) ((x > y) ? x : y)

int maxSubArray(int* nums, int numsSize) {
    int sum = 0;
    int max_sum = INT32_MIN;

    for (int i = 0; i < numsSize; i++) {
        if (sum < 0) {
            sum = 0;
        }
        sum += nums[i];
        max_sum = MAX(max_sum, sum);
    }

    return max_sum;
}
