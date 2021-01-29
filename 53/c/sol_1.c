/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 53. Maximum Subarray
 * @date 2021.01.29
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#define MAX(x, y) ((x > y) ? x : y)

int maxSubArray(int* nums, int numsSize) {
    int sum = nums[0];
    int pre_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        sum = MAX(nums[i], sum + nums[i]);
        pre_sum = MAX(pre_sum, sum);
    }

    return pre_sum;
}
