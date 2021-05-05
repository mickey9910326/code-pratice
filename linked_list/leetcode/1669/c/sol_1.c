/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1669. Merge In Between Linked Lists
 * @date 2021.05.05
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

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b,
                                struct ListNode* list2) {
    struct ListNode* p = list1;
    struct ListNode* q = list1;

    for (int i = 0; i < a - 1; i++) {
        p = p->next;
    }
    for (int i = 0; i < b + 1; i++) {
        q = q->next;
    }

    p->next = list2;
    while (list2->next) {
        list2 = list2->next;
    }
    list2->next = q;
    return list1;
}
