/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 725. Split Linked List in Parts
 * @date 2021.05.03
 *
 * Time Complexity: O(n + k)
 * Space Complexity: O(n + k)
 *   n is length of list
 *   k is num of parts
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

struct ListNode* node_create(int val) {
    struct ListNode* p = malloc(sizeof(struct ListNode));
    p->val = val;
    p->next = NULL;
    return p;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k,
                                   int* returnSize) {
    struct ListNode** res = malloc(sizeof(struct ListNode*) * k);
    *returnSize = k;

    struct ListNode* prev;
    struct ListNode* curr;

    int listsize = 0;
    curr = root;
    while (curr) {
        curr = curr->next;
        listsize++;
    }

    int idx = 0;
    int len;

    prev = NULL;
    curr = root;
    for (idx = 0; idx < k; idx++) {
        len = listsize / k + ((listsize % k) > idx ? 1 : 0);

        if (len == 0) {
            // no nodes in this section
            res[idx] = NULL;
            continue;
        }

        res[idx] = curr;

        // shift curr to tail of this section
        for (int i = 0; i < len; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
    }

    return res;
}
