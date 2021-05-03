"""leetcode 877. Stone Game

   Time Complexity: O(n^2)

   minimax + DP
"""


from collections import defaultdict


class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        self.dp_table = defaultdict(int)

        def mm_gap(piles, l, r):

            if l == r:
                return piles[l]

            if (l, r) in self.dp_table:
                return self.dp_table[(l, r)]

            choose_left = piles[l] - mm_gap(piles, l+1, r)
            choose_right = piles[r] - mm_gap(piles, l, r-1)

            self.dp_table[(l, r)] = max(choose_left, choose_right)

            return self.dp_table[(l, r)]

        score_gap = mm_gap(piles, l=0, r=len(piles)-1)

        return score_gap > 0
