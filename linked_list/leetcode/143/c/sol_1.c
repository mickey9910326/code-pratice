/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 143. Reorder List
 * @date 2021.05.02
 *
 * Time Complexity: O(n)
 * Space Complexity: 1
 *
 * Method:
 *  1. get the middle node by slow and fast pointer
 *     cut list to two lists, left side and right side
 *  2. reverse right side list
 *  3. insert each node of right side to left side
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head) {
    struct ListNode* p = head;
    struct ListNode* q = head;

    // find middle node
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
    }
    // middle node would be p->next
    //     as start of right side list

    struct ListNode* prev = NULL;
    struct ListNode* curr = p->next;
    struct ListNode* next;

    // reverse right side list form p
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode* l = head;
    struct ListNode* r = prev;
    // make last node of left side list become NULL
    p->next = NULL;

    // insert right side list to left list
    while (l && r) {
        next = l->next;
        l->next = r;
        r = r->next;
        l->next->next = next;
        l = next;
    }
}
