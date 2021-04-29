/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 19. Remove Nth Node From End of List
 * @date 2021.04.29
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

void helper(struct ListNode* head, int& n) {
    if (head == NULL) {
        return;
    }
    helper(head->next, n);
    n--;
    if (*n == -1) {
        head->next = head->next->next;
    }
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    helper(head, &n);
    return head;
}
