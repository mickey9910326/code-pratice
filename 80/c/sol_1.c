/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 80. Remove Duplicates from Sorted Array II
 * @date 2020.12.09
 * 
 */

int removeDuplicates(int* nums, int numsSize) {
    // exceptions
    if (numsSize == 0) {
        return 0;
    }
    
    int idx = 0;  ///< idx of new array tail
    int count = 1;  ///< new item count
    int val = nums[0];  ///< previous value to compare in array search

    /**
     * Index 0 of intput array is always a new item for new array.
     * And it's already in the index 0 of the array.
     * Dosent need to assign value again.
     */

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == val && count == 1) {
            idx++;
            nums[idx] = val;
            count++;
        }
        else if (nums[i] != val) {
            idx++;
            val = nums[i];
            nums[idx] = val;
            count = 1;
        }
    }

    return idx + 1;
}