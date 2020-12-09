"""leetcode 80. Remove Duplicates from Sorted Array II
"""


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #  exceptions
        if not nums:
            return 0
        elif len(nums) == 1:
            # this condiction cost less than "for num in nums[1::]"
            return 1

        idx = 0  # idx of new array tail
        count = 1  # new item count
        val = nums[0]  # previous value to compare in array search

        # Index 0 of intput array is always a new item for new array.
        # And it's already in the index 0 of the array.
        # Dosent need to assign value again.

        for num in nums[1::]:
            if num == val and count == 1:
                idx += 1
                nums[idx] = val
                count += 1
            elif num != val:
                idx += 1
                val = num
                nums[idx] = val
                count = 1

        return idx + 1
