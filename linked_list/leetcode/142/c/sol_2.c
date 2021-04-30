/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 142. Linked List Cycle II
 * @date 2020.12.09
 *
 * Time Complexity: O(n^2)
 * Space Complexity: 1
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * @brief
 *
 * @param head
 * @return struct ListNode*
 */
struct ListNode *detectCycle(struct ListNode *head) {

    struct ListNode *p1 = head;
    struct ListNode *p2;
    int i = 0;
    int j = 0;

    while (p1 != NULL) {
        // compare each node
        p2 = head;
        while (j < i) {
            if (p1->next == p2) {
                return p1;
            }

            j++;
            p2 = p2->next;
        }

        i++;
        p1 = p1->next;
    }
    return NULL;
}
