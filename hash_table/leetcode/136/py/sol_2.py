"""136. Single Number
   use xor.

   Time Complexity: O(n)
   Space Complexity: O(1)
"""

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ret = 0
        for num in nums:
            ret ^= num
        return ret
