/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief 24. Swap Nodes in Pairs
 * @date 2021.04.27
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

#include <stdlib.h>

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode* p;
    struct ListNode* q;
    int tmp;

    p = head;
    while (1) {
        if (p == NULL) {
            break;
        }
        if (p->next == NULL) {
            break;
        }

        p = p;
        q = p->next;

        tmp = p->val;
        p->val = q->val;
        q->val = tmp;

        p = q->next;
    }

    return head;
}
