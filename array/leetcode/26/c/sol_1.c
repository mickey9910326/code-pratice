/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 26. Remove Duplicates from Sorted Array
 * @date 2020.12.09
 * 
 */

int removeDuplicates(int* nums, int numsSize) {
    // exception for null array []
    if (numsSize == 0) {
        return 0;
    }
    
    int count = 1;  ///< count of new array items
    int val = nums[0];  ///< previous value to compare in array search

    /**
     * Index 0 of intput array is always a new item for new array.
     * And it's already in the index 0 of the array.
     * Dosent need to assign value again.
     */

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != val) {
            val = nums[i];
            nums[count] = val;
            count++;
        }
    }

    return count;
}