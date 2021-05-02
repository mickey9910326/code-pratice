/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 147. Insertion Sort List
 * @date 2021.05.02
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

struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode sentinel = {.next = head};
    struct ListNode* p;
    struct ListNode* prev;
    struct ListNode* curr;

    p = head;
    while (p && p->next) {
        prev = &sentinel;
        curr = sentinel.next;
        while (curr != p->next) {
            if (p->next->val <= curr->val) {
                break;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        if (curr != p->next) {
            prev->next = p->next;
            p->next = p->next->next;
            prev->next->next = curr;
        }
        else {
            p = p->next;
        }
    }
    return sentinel.next;
}
