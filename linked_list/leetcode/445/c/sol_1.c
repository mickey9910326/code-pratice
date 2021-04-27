/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 445. Add Two Numbers II
 * @date 2021.04.27
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * First, reverse l1 and l2.
 * Than, do the same algo of leetcode 2. Add Two Numbers.
 * At last, reverse the result.
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

struct ListNode* reverse_list(struct ListNode* p) {
    struct ListNode* pre = NULL;
    struct ListNode* next = NULL;
    while (p != NULL) {
        next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }
    return pre;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    struct ListNode* p1 = reverse_list(l1);  // index pointer for l1
    struct ListNode* p2 = reverse_list(l2);  // index pointer for l2
    struct ListNode* p3 = NULL;              // index pointer for list res
    struct ListNode* res = NULL;
    int val;
    int carry = 0;

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

    return reverse_list(res);
}
