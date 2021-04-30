"""leetcode 26. Remove Duplicates from Sorted Array
sol.2 fix line21
Only use [1::] of list to compare, index 0 is used im line 15 and 16.
"""

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #  exception for null array []
        if not nums:
            return 0
        elif len(nums) == 1:
            # this condiction cost less than "for num in nums[1::]"
            return 1
        
        count = 1  # count of new array items
        val = nums[0] # previous value to compare in array search

        # Index 0 of intput array is always a new item for new array.
        # And it's already in the index 0 of the array.
        # Dosent need to assign value again.

        for num in nums[1::]:
            if num != val:
                val = num
                nums[count] = val
                count = count + 1
        
        return count
