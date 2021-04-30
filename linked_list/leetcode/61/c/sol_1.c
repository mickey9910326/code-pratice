/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 61. Rotate List
 * @date 2021.04.30
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) {
        return head;
    }

    struct ListNode* curr = head;
    int len = 0;

    while (curr->next) {
        curr = curr->next;
        len++;
    }
    curr->next = head;

    curr = head;

    for (int i = 0; i < len - (k % (len + 1)); i++) {
        curr = curr->next;
    }

    head = curr->next;
    curr->next = NULL;

    return head;
}
