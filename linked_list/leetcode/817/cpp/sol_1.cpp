/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 817. Linked List Components
 * @date 2021.05.05
 *
 * Time Complexity: O(nlog(g))
 * Space Complexity: O(n)
 *   n is length of list
 *   g is length of G
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    int numComponents(ListNode* head, vector<int>& G) {
        std::set<int> s;
        int res = 0;

        // Traverse the Vector G
        for (int x : G) {
            s.insert(x);
        }

        while (head) {
            if (s.find(head->val) != s.end()) {
                if (head->next == NULL) {
                    res++;
                }
                else if (s.find(head->next->val) == s.end()) {
                    res++;
                }
            }
            head = head->next;
        }
        return res;
    }
};
