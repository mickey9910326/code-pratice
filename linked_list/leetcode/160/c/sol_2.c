/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 160. Intersection of Two Linked Lists
 * @date 2021.05.01
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

int list_len(struct ListNode *p) {
    int len = 0;
    while (p) {
        p = p->next;
        len++;
    }
    return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
    int lenA = list_len(headA);
    int lenB = list_len(headB);

    struct ListNode *l_list;  // longer list of headA and headB
    struct ListNode *s_list;  // shorter list of headA and headB
    int lengap;

    if (lenA >= lenB) {
        l_list = headA;
        s_list = headB;
        lengap = lenA - lenB;
    }
    else {
        l_list = headB;
        s_list = headA;
        lengap = lenB - lenA;
    }

    for (int i = 0; i < lengap; i++) {
        l_list = l_list->next;
    }

    while (l_list && l_list != s_list) {
        l_list = l_list->next;
        s_list = s_list->next;
    }

    return l_list;
}
