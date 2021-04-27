/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief 1721. Swapping Nodes in a Linked List
 * @date 2021.04.27
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

#include <stdlib.h>

int list_len(struct ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
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

struct ListNode* swapNodes(struct ListNode* head, int k) {
    int len = list_len(head);

    if (len == 1) {
        return head;
    }

    struct ListNode sentinel = {.next = head};

    struct ListNode* p = head;
    struct ListNode* q = head;
    struct ListNode* pre_p = &sentinel;
    struct ListNode* pre_q = &sentinel;
    struct ListNode* tmp;

    if (k == len - k + 1) {
        return head;
    }

    // NOTE: list is 1-indexed
    for (int i = 1; i < k; i++) {
        pre_p = p;
        p = p->next;
    }
    for (int i = 1; i < len - k + 1; i++) {
        pre_q = q;
        q = q->next;
    }

    pre_p->next = q;
    pre_q->next = p;

    tmp = p->next;
    p->next = q->next;
    q->next = tmp;

    return sentinel.next;
}
