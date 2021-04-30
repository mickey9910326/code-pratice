/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 206. Reverse Linked List
 * @date 2021.05.01
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Recursive method
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* p = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return p;
}
