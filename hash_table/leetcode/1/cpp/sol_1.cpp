/**
 * @file sol_1.cpp
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1. Two Sum
 * @date 2020.05.13
 *
 * use hash table
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        std::unordered_map<int, int> umap;
        std::unordered_map<int,int>::iterator it;

        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums.at(i);

            it = umap.find(diff);
            if(it != umap.end()) {
                res.push_back(i);
                res.push_back(umap[diff]);
                break;
            }

            umap[nums.at(i)] = i;
        }
        return res;
    }
};
