/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 206. Reverse Linked List
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

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* pre = NULL;
    struct ListNode* next = NULL;

    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    return pre;
}
