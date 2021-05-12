/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 23. Merge k Sorted Lists
 * @date 2021.05.12
 *
 * Compare each head of lists, find the mininum
 * and add to new list.
 *
 * Time Complexity: O(kn)
 * Space Complexity: O(1)
 *
 * k is listsSize
 * n is total num of nodes
 *
 * Worst than sol_1.c because it have more campare action
 * and if statemant.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL) {
        return NULL;
    }

    if (listsSize == 1) {
        return lists[0];
    }

    struct ListNode dummy = {.next = NULL};
    struct ListNode* curr = &dummy;
    struct ListNode* min;

    int min_idx;

    while (1) {
        min = NULL;

        for (int i = 0; i < listsSize; i++) {
            if (lists[i]) {
                if (min == NULL) {
                    min = lists[i];
                    min_idx = i;
                }
                else if (min->val > lists[i]->val) {
                    min = lists[i];
                    min_idx = i;
                }
            }
        }

        if (min) {
            curr->next = min;
            curr = curr->next;
            lists[min_idx] = lists[min_idx]->next;
        }
        else {
            // min mode is NULL means all list length is 0
            break;
        }
    }

    curr->next = NULL;

    return dummy.next;
}
