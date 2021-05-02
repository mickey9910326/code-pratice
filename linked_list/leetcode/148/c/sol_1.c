/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 148. Sort List
 * @date 2021.05.03
 *
 * Time Complexity: O(nlog(n))
 * Space Complexity: O(n)
 *
 * merge sort
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    struct ListNode sentenil = {.next = NULL};
    struct ListNode* curr = &sentenil;

    while (left && right) {
        if (left->val <= right->val) {
            curr->next = left;
            left = left->next;
        }
        else {
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }

    if (left) {
        curr->next = left;
    }
    else if (right) {
        curr->next = right;
    }

    return sentenil.next;
}

struct ListNode* merge_sort(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL) {
        return head;
    }

    struct ListNode* prev = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) {
        prev->next = NULL;
    }

    struct ListNode* left = merge_sort(head);   // left side
    struct ListNode* right = merge_sort(slow);  // right side
    struct ListNode* ret = merge(left, right);

    return ret;
}

struct ListNode* sortList(struct ListNode* head) {
    return merge_sort(head);
}
