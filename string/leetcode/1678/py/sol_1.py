"""leetcode 1678. Goal Parser Interpretation

   Time Complexity: O(n)
"""


class Solution:
    def interpret(self, command: str) -> str:
        s = ""

        al_flag = bool(False)

        for ch in command:
            if ch == 'G':
                s += 'G'
            elif ch == '(':
                pass
            elif ch == ')':
                if al_flag:
                    al_flag = False
                    s += 'al'
                else:
                    s += 'o'
            elif ch == 'a':
                al_flag = True
            elif ch == 'l':
                pass

        return s
