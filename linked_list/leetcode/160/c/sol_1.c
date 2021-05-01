/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 160. Intersection of Two Linked Lists
 * @date 2021.05.01
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
    struct ListNode *p;
    struct ListNode *q;

    p = headA;

    while (p && p != q) {
        q = headB;
        while (q && p != q) {
            q = q->next;
        }
        if (p == q) {
            break;
        }
        p = p->next;
    }

    return p;
}
