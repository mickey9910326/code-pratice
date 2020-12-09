/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 26. Remove Duplicates from Sorted Array
 * @date 2020.12.09
 * 
 * Remove variable "val", and use "idx" as a index of 
 * new array to get previous value.
 * And get new array count by "idx" + 1 .
 */

int removeDuplicates(int* nums, int numsSize) {
    // exception for null array []
    if (numsSize == 0) {
        return 0;
    }
    
    int idx = 0;  ///< ndex of new array

    /**
     * Index 0 of intput array is always a new item for new array.
     * And it's already in the index 0 of the array.
     * Dosent need to assign value again.
     */

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[idx]) {
            nums[idx] = nums[i];
        }
    }

    return idx + 1;
}