/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 445. Add Two Numbers II
 * @date 2021.04.27
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Recursive way.
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

void addTwoNumbers_helper(struct ListNode* l1, struct ListNode* l2,
                          struct ListNode* res, int len_l1, int len_l2,
                          int* carry) {
    int val = 0;
    struct ListNode* p = new_node(val);
    printf("%d,%d\n", len_l1, len_l2);

    if (len_l1 > len_l2) {
        val += l1->val;

        l1 = l1->next;
        len_l1 -= 1;
    }
    else if (len_l1 < len_l2) {
        val += l2->val;

        l2 = l2->next;
        len_l2 -= 1;
    }
    else {
        val += l1->val;
        val += l2->val;

        l1 = l1->next;
        len_l1 -= 1;
        l2 = l2->next;
        len_l2 -= 1;
    }

    if (len_l1 > 0) {
        addTwoNumbers_helper(l1, l2, res, len_l1, len_l2, carry);
    }

    val += *carry;
    p = new_node(val);

    *carry = val / 10;
    val %= 10;

    p->next = res;
    res = p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    int len_l1 = list_len(l1);
    int len_l2 = list_len(l2);
    int carry = 0;

    struct ListNode* res = NULL;
    struct ListNode* p = NULL;

    addTwoNumbers_helper(l1, l2, res, len_l1, len_l2, &carry);

    if (carry > 0) {
        p = new_node(carry);
        p->next = res;
        res = p;
    }

    return res;
}
