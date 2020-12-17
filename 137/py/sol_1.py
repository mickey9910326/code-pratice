"""137. Single Number II
   use hash table.

   Time complexity: O(n)
   Space complexity: O(n)
"""

import collections


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        c = collections.Counter(nums)
        ret = []

        for element, count in c.items():
            if count == 1:
                ret.append(element)

        return ret
