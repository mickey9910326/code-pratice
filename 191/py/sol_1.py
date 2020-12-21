"""191. Number of 1 Bits

   Time complexity: O(1)
   Space complexity: O(1)
"""


class Solution:
    def hammingWeight(self, n: int) -> int:
        # python 3.10 可用 n.bit_count() 來改寫

        # NOTE 此方法pyhton將其轉為'0'與'1'組成之字串
        # 並計算'1'出現的次數
        return bin(n).count("1")
