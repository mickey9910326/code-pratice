/**
 * @file sol_1.cpp
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 430. Flatten a Multilevel Doubly Linked List
 * @date 2021.05.12
 *
 * Time Complexity:
 *   best is O(n) worst is O(n^2)
 *   avg is O(nlog(n)) ?
 * Space Complexity:
 *   best is O(1) worst is O(n)
 *   avg is O(log(n)) ?
 *
 * n is nums of nodes
 *
 * TODO: Evaluate the complexity.
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
        Node* curr = head;
        Node* child;
        Node* tmp = NULL;

        while (curr) {
            if (curr->child) {
                child = flatten(curr->child);
                tmp = curr->next;
                curr->child = NULL;
                curr->next = child;
                child->prev = curr;
            }

            if (curr->next == NULL && tmp) {
                curr->next = tmp;
                tmp->prev = curr;
                tmp = NULL;
            }

            curr = curr->next;
        }

        return head;
    }
};
