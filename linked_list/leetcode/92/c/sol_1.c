/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 92. Reverse Linked List II
 * @date 2021.05.12
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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL) {
        return NULL;
    }
    if (left == right) {
        return head;
    }

    struct ListNode dummy = {.next = head};
    struct ListNode* prev_l = &dummy;
    struct ListNode* next_r;
    struct ListNode* l = head;
    struct ListNode* r = head;

    for (int i = 1; i < left; i++) {
        prev_l = l;
        l = l->next;
    }
    for (int i = 1; i < right; i++) {
        r = r->next;
    }
    next_r = r->next;

    prev_l->next = r->next;

    struct ListNode* prev = prev_l;
    struct ListNode* curr = l;
    struct ListNode* next;
    while (curr != next_r) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    l->next = next_r;
    prev_l->next = r;
    return dummy.next;
}
