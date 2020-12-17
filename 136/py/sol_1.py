"""
   use set.

   Time Complexity: avg. is O(n), worst is O(n^2).
   Space Complexity: O(n)
"""


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        s = set()

        for num in nums:
            if num in s:
                s.remove(num)
            else:
                s.add(num)

        return s.pop()
