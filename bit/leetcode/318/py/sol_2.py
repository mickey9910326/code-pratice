"""318. Maximum Product of Word Lengths

   Brute-force method.

   NOTE:
     In line "if ch in word2",
     it will turn word2 each element into a set and than search.
     So it take less time than method "sol_1.c".

   Time Complexity: O(n^2 * m)
     n is length of words.
     m is avg. length of a word in words.
   Space Complexity: O(1)
"""

from itertools import combinations


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        ascii_sets = [set(word) for word in words]

        words_size = len(words)
        ret = 0

        for word1, word2 in combinations(words, 2):
            passed = True

            for ch in word1:
                if ch in word2:
                    passed = False
                    break

            if passed:
                ret = max(ret, len(word1) * len(word2))

        return ret
