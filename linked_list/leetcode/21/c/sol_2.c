/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 21. Merge Two Sorted Lists
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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    struct ListNode sentinel;
    struct ListNode* curr = &sentinel;

    while (l1 && l2) {
        if (l1->val >= l2->val) {
            curr->next = l2;
            l2 = l2->next;
        }
        else {
            curr->next = l1;
            l1 = l1->next;
        }
        curr = curr->next;
    }
    if (l2) {
        // l1 reach tail and l2 doesnot
        curr->next = l2;
    }
    if (l1) {
        // l2 reach tail and l1 doesnot
        curr->next = l1;
    }

    return sentinel.next;
}
