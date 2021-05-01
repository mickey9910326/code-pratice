/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 203. Remove Linked List Elements
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

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode sentinel = {.next = head};
    struct ListNode* prev = &sentinel;
    struct ListNode* curr = head;

    while (curr) {
        if (curr->val == val) {
            prev->next = curr->next;
        }
        else {
            prev = curr;
        }
        curr = curr->next;
    }

    return sentinel.next;
}
