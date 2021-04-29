/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 21. Merge Two Sorted Lists
 * @date 2021.04.29
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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    struct ListNode sentinel = {.next = l1};
    struct ListNode* pre = &sentinel;
    struct ListNode* curr = l1;

    while (curr && l2) {
        if (curr->val >= l2->val) {
            pre->next = l2;
            l2 = l2->next;
            pre->next->next = curr;
            pre = pre->next;
        }
        else {
            pre = curr;
            curr = curr->next;
        }
    }
    if (l2) {
        // l1 reach tail and l2 doesnot
        pre->next = l2;
    }
    if (curr) {
        // l2 reach tail and l1 doesnot
        // donothing
    }

    return sentinel.next;
}
