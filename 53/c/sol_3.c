/**
 * @file sol_3.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 53. Maximum Subarray
 * @date 2021.01.29
 *
 * use divide and conquer approach
 *
 * Time Complexity: O(n*log(n))
 * Space Complexity: O(log(n))
 */

#include <stdint.h>

#define MAX(x, y) ((x > y) ? x : y)

int maxSubArray(int* nums, int numsSize) {
    return maxSubArrayHelper(nums, 0, numsSize - 1);
}

int maxSubArrayHelper(int* nums, int s, int e) {
    if (s >= e) {
        return nums[s];
    }

    int m = s + (e - s) / 2;  // index of middle
    int mmax = maxSubArrayFromMid(nums, s, e, m);

    int lmax = maxSubArrayHelper(nums, s, m);
    int rmax = maxSubArrayHelper(nums, m + 1, e);

    return MAX(mmax, MAX(lmax, rmax));
}

int maxSubArrayFromMid(int* nums, int s, int e, int m) {
    int lmax = nums[m];
    int rmax = nums[m + 1];
    int sum;

    // start <-- middle - 1
    sum = nums[m];
    for (int i = m - 1; i >= s; i--) {
        sum += nums[i];
        lmax = MAX(lmax, sum);
    }

    // middle + 2 --> end
    sum = nums[m + 1];
    for (int i = m + 2; i <= e; i++) {
        sum += nums[i];
        rmax = MAX(rmax, sum);
    }
    return MAX(lmax + rmax, MAX(lmax, rmax));
}
