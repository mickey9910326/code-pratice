/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 83. Remove Duplicates from Sorted List
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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode* curr = head;

    while (curr && curr->next) {
        if (curr->next->val == curr->val) {
            curr->next = curr->next->next;
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}
