/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 86. Partition List
 * @date 2021.05.12
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

struct ListNode* partition(struct ListNode* head, int x) {

    struct ListNode dummy_less = {.next = NULL};
    struct ListNode dummy_gteater = {.next = NULL};

    struct ListNode* less = &dummy_less;
    struct ListNode* greater = &dummy_gteater;

    while (head) {
        if (head->val >= x) {
            greater->next = head;
            greater = greater->next;
        }
        else {
            less->next = head;
            less = less->next;
        }
        head = head->next;
    }

    less->next = dummy_gteater.next;
    greater->next = NULL;

    return dummy_less.next;
}
