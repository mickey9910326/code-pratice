/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief 1171. Remove Zero Sum Consecutive Nodes from Linked List
 * @date 2021.04.27
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

#include <stdlib.h>

/**
 * Use sentinel node to avoid boundary case
 * NOTE: this function doesn't free memory of useless nodes.
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode sentinel = {.next = head, .val = 0};
    struct ListNode* pre_p = &sentinel;
    struct ListNode* p = head;
    struct ListNode* q = head;

    int sum = 0;
    int num2 = 0;

    while (p != NULL) {
        sum = p->val;

        q = p->next;
        while (q != NULL && sum != 0) {
            sum += q->val;

            // NOTE: q will pointer to next node even though sum is zero
            q = q->next;
        }

        if (sum == 0) {
            // the sum of node p to pre node of q is zero
            // remove them out of list
            pre_p->next = q;
            p = q;
        }
        else {
            pre_p = p;
            p = p->next;
        }
    }

    return sentinel.next;
}
