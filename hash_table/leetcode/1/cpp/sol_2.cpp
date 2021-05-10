/**
 * @file sol_2.cpp
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1. Two Sum
 * @date 2020.05.13
 *
 * use hash table
 * more clear code
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums.at(i);

            if (map.find(diff) != map.end()) {
                return {i, map[diff]};
            }

            map[nums.at(i)] = i;
        }

        return {};
    }
};
