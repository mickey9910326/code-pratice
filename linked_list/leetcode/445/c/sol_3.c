/**
 * @file sol_3.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 445. Add Two Numbers II
 * @date 2021.04.27
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Determine of two list.
 * Put the high digit nums of longer list to result list.
 * Add two list to result list without carry part in for loop.
 * Do the carry part in recursive way
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

// struct ListNode {
//     int val;
//     struct ListNode* next;
// };

struct ListNode* new_node(int val) {
    struct ListNode* p = malloc(sizeof(struct ListNode));
    p->next = NULL;
    p->val = val;
    return p;
}

int list_len(struct ListNode* p) {
    int len = 0;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

void do_carry(struct ListNode* p, int* carry) {
    if (p != NULL) {
        do_carry(p->next, carry);
        p->val += *carry;

        *carry = p->val / 10;
        p->val %= 10;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    int len_l1 = list_len(l1);
    int len_l2 = list_len(l2);

    struct ListNode* p1;  // index pointer for the longer list of l1, l2
    struct ListNode* p2;  // index pointer for the shorter list of l1, l2
    struct ListNode* head = NULL;
    struct ListNode* curr = NULL;

    int digit_diff;
    int len;
    int val;
    int carry;

    if (len_l1 >= len_l2) {
        p1 = l1;
        p2 = l2;
        digit_diff = len_l1 - len_l2;
        len = len_l1 - digit_diff;
    }
    else {
        p1 = l2;
        p2 = l1;
        digit_diff = len_l2 - len_l1;
        len = len_l2 - digit_diff;
    }

    for (int i = 0; i < digit_diff; i++) {
        if (head == NULL) {
            // no list created
            head = new_node(p1->val);
            curr = head;
        }
        else {
            curr->next = new_node(p1->val);
            curr = curr->next;
        }
        p1 = p1->next;
    }

    for (int i = 0; i < len; i++) {
        val = p1->val + p2->val;

        if (head == NULL) {
            // no list created
            head = new_node(val);
            curr = head;
        }
        else {
            curr->next = new_node(val);
            curr = curr->next;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    do_carry(head, &carry);

    return head;
}
