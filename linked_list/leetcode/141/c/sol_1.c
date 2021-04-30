/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 141. Linked List Cycle I
 * @date 2020.12.09
 *
 * slow poninter and fast pointer
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
 * @return true
 * @return false
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *fp = head;
    struct ListNode *sp = head;

    while (1) {
        sp = sp->next;
        fp = fp->next->next;

        if (fp == NULL || fp->next == NULL) {
            return false;
        }
        if (fp == sp) {
            return true;
        }
    }

}
