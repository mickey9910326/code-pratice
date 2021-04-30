/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 82. Remove Duplicates from Sorted List II
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

#include <stdbool.h>
#include <stdlib.h>

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode sentinel = {.next = head};
    struct ListNode* pre = &sentinel;
    struct ListNode* curr = head;
    bool duplicated = false;

    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            curr = curr->next;
            duplicated = true;
        }
        else {
            if (duplicated) {
                duplicated = false;
                pre->next = curr->next;
                curr = curr->next;
            }
            else {
                pre = curr;
                curr = curr->next;
            }
        }
    }
    if (duplicated) {
        pre->next = curr->next;
    }

    return sentinel.next;
}
