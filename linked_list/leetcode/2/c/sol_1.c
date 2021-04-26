/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 2. Add Two Numbers
 * @date 2020.12.23
 *
 * Time Complexity: O(n) based on digit of number 'x'
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1 = l1;    // index pointer for l1
    struct ListNode* p2 = l2;    // index pointer for l2
    struct ListNode* p3 = NULL;  // index pointer for list res
    struct ListNode* res = NULL;
    int val;
    int carry = 0;

    if (p1 == NULL && p2 == NULL) {
        return NULL;
    }

    while ((p1 != NULL) || (p2 != NULL)) {
        val = 0;
        if (p1) {
            val += p1->val;
            p1 = p1->next;
        }
        if (p2) {
            val += p2->val;
            p2 = p2->next;
        }
        val += carry;

        carry = val / 10;
        val %= 10;

        if (p3 == NULL) {
            // first time of loop
            res = new_node(val);
            p3 = res;
        }
        else {
            p3->next = new_node(val);
            p3 = p3->next;
        }
    }

    if (carry > 0) {
        p3->next = new_node(carry);
    }

    return res;
}
