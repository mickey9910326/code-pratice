"""leetcode 26. Remove Duplicates from Sorted Array
"""

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #  exception for null array []
        if not nums:
            return 0
        
        count = 1  # count of new array items
        val = nums[0] # previous value to compare in array search

        # Index 0 of intput array is always a new item for new array.
        # And it's already in the index 0 of the array.
        # Dosent need to assign value again.

        for num in nums:
            if num != val:
                val = num
                nums[count] = val
                count = count + 1
        
        return count
