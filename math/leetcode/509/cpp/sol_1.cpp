/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 509. Fibonacci Number
 * @date 2021.05.05
 *
 * Time Complexity:
 *   First time access index n is O(n).
 *   After first time is O(1).
 * Space Complexity: O(n)
 *
 */

static std::vector<int> Fibs = {0, 1};

class Solution {
public:
    int fib(int n) {
        int sz = Fibs.size();
        int val;

        if (n >= sz) {
            for (int i = sz; i <= n; i++) {
                val = Fibs.at(i-1) + Fibs.at(i-2);
                Fibs.push_back(val);
            }
        }
        else {
            val = Fibs.at(n);
        }
        return val;
    }
};
