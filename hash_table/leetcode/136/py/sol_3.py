"""136. Single Number
   use hash table.

   Time complexity: O(n)
   Space complexity: O(n)
"""

import collections


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        c = collections.Counter(nums)
        ret = 0

        for element, count in c.items():
            if count == 1:
                ret = element

        return ret
