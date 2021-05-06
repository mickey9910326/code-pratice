/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1019. Next Greater Node In Linked List
 * @date 2021.05.06
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next;
    int list_size = 0;

    // reverse list and get length
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        list_size++;
    }
    *returnSize = list_size;

    volatile int* res = malloc(sizeof(int) * (list_size));
    int idx = list_size - 1;

    int* stack = malloc(sizeof(int) * (list_size + 1));
    int st_idx = 0;
    stack[0] = 0;

    int max = head->val;

    curr = prev;
    while (curr) {
        while (st_idx > 0) {
            if (stack[st_idx] > curr->val) {
                res[idx] = stack[st_idx];
                break;
            }
            else {
                st_idx--;
            }
        }
        res[idx] = stack[st_idx];

        st_idx++;
        stack[st_idx] = curr->val;

        idx--;
        curr = curr->next;
    }

    return res;
}
