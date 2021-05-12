/**
 * @file sol_2.cpp
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 430. Flatten a Multilevel Doubly Linked List
 * @date 2021.05.12
 *
 * Time Complexity: O(n)
 * Space Complexity:
 *   best is O(1) worst is O(n)
 *   avg is O(log(n)) ?
 *
 * n is nums of nodes
 *
 * Definition for a Node.
 * class Node {
 * public:
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node* child;
 * };
 */

class Solution {
   public:
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }

   private:
    Node* helper(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* child;
        Node* next = NULL;

        while (curr) {
            if (curr->child) {
                next = curr->next;

                curr->next = curr->child;
                curr->child->prev = curr;

                curr->child = NULL;

                curr = helper(curr->next);
                curr->next = next;
                if(next) {
                   next->prev = curr;
                }
            }

            prev = curr;
            curr = curr->next;
        }

        return prev;
    }
};
