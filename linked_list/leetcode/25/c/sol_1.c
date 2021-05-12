/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 25. Reverse Nodes in k-Group
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

struct ListNode* reverse(struct ListNode* head, struct ListNode* tail) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next;

    while (curr != tail) {
        // printf("%d -> ", curr->val);
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // printf("NULL\n");

    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL) {
        return head;
    }
    if (k == 1) {
        return head;
    }

    struct ListNode dummy = {.next = head};
    struct ListNode* prev_tail = &dummy;
    struct ListNode* curr_head = head;
    struct ListNode* next_head;
    int count = 0;

    while (head) {
        count++;
        head = head->next;
        if (count == k) {
            next_head = head;
            prev_tail->next = reverse(curr_head, next_head);

            // curr_head become tail
            curr_head->next = next_head;
            prev_tail = curr_head;
            curr_head = next_head;
            count = 0;
        }
    }
    return dummy.next;
}
