/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 237. Delete Node in a Linked List
 * @date 2021.05.01
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Iterative method
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

void deleteNode(struct ListNode* node) {
    if (node == NULL) {
        return;
    }

    struct ListNode* prev = NULL;

    while (node->next) {
        node->val = node->next->val;
        prev = node;
        node = node->next;
    }

    if (prev) {
        prev->next = NULL;
    }
}
