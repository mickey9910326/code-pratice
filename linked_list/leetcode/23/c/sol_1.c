/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 23. Merge k Sorted Lists
 * @date 2021.05.12
 *
 * Use loop merge 2 lists in k Sorted Lists
 *
 * Time Complexity: O(kn)
 * Space Complexity: O(1)
 *
 * k is listsSize
 * n is total num of nodes
 *
 * Better than sol_2.c because this method dosn't need to
 * compare some nodes adjacent to tail.
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL) {
        return NULL;
    }

    if (listsSize == 0) {
        return NULL;
    }

    if (listsSize == 1) {
        return lists[0];
    }

    struct ListNode* l = lists[0];

    for (int i = 1; i < listsSize; i++) {
        l = mergeTwoLists(l, lists[i]);
    }

    return l;
}