/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief 136. Single Number
 * @date 2020.12.16
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

int singleNumber(int* nums, int numsSize) {
    int i;
    int ret = 0;

    for (i = 0; i < numsSize; i++) {
        ret ^= nums[i];
    }

    return ret;
}
