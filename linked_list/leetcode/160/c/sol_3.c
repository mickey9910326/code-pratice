/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 160. Intersection of Two Linked Lists
 * @date 2021.05.01
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

struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    struct ListNode *a = headA;
    struct ListNode *b = headB;

    // a always meet B at intersect
    // because both the visit path is
    //      len(headA) + len(headB) - len(intersect to tail)
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }

    return a;
}
