/**
 * @file sol_2.cpp
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1. Two Sum
 * @date 2020.05.13
 *
 * brute force method
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize =  2;
    int *res = (int*)malloc(2*sizeof(int));
    int min = INT_MAX;
    for (int i=0; i<numsSize; i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
    }

    int max = INT_MIN;
    for (int i=0; i<numsSize; i++) {
        if (max < nums[i]) {
            max = nums[i];
        }
    }

	int len = max - min + 1;
    if (len == 1) {
        res[0] = 0;
        res[1] = 1;
        return res;
    }

    int *t = (int*)malloc(len*sizeof(int));
    for (int i=0; i<len; i++) {
        t[i] = -1;
    }

    for (int i=0; i<numsSize; i++) {
        if (nums[i] - min < len) {
            t[nums[i]-min] = i;
        }
    }

    for (int i=0; i<numsSize; i++) {
        if (nums[i] - min < len && target-nums[i]-min >= 0) {
            if (t[target-nums[i]-min] != -1) {
                res[0] = i;
                res[1] = t[target-nums[i]-min];
                free(t);
                return res;
            }
        }
    }
    free(t);
    return res;
}
