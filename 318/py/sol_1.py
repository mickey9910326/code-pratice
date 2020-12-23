"""318. Maximum Product of Word Lengths

   Use set to store appeared ascii in a word.

   Time Complexity: O(n^2)
   Space Complexity: O(n)
"""

from itertools import combinations


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        ascii_sets = [set(word) for word in words]

        words_size = len(words)
        ret = 0

        for (w1, s1), (w2, s2) in combinations(zip(words, ascii_sets), 2):
            passed = True

            for ch in s1:
                if ch in s2:
                    passed = False
                    break

            if passed:
                ret = max(ret, len(w1) * len(w2))

        return ret
