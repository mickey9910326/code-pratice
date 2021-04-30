/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 142. Linked List Cycle II
 * @date 2020.12.09
 *
 * Time Complexity: O(n)
 * Space Complexity: 1
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * @brief
 *
 * @param head
 * @return struct ListNode*
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode *fp = head;
    struct ListNode *sp = head;

    while (1) {
        sp = sp->next;
        fp = fp->next->next;

        if (fp == NULL || fp->next == NULL) {
            return NULL;
        }
        if (fp == sp) {
            break;
        }
    }

    sp = head;
    while (sp != fp) {
        sp = sp->next;
        fp = fp->next;
    }
    return sp;
}
