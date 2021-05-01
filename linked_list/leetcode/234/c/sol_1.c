/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 234. Palindrome Linked List
 * @date 2021.05.01
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Iterative method
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(struct ListNode* head) {
    // length 0, 1 is palindrome
    if (head == NULL) {
        return true;
    }
    if (head->next == NULL) {
        return true;
    }

    bool is_palindrome = false;
    int len = 0;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next;

    // detect length
    while (curr) {
        curr = curr->next;
        len++;
    }

    // cut list to two side left and right
    // and reverse left side
    curr = head;
    for (int i = 0; i < len / 2; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode* left = prev;
    struct ListNode* right = next;

    // if list length is odd, right node move 1 step first
    if (len % 2 == 1) {
        right = right->next;
    }

    // compare each node value in left and right
    while (left && left->val == right->val) {
        left = left->next;
        right = right->next;
    }

    // left meet end
    // means all node values of left and right is the same
    if (left == NULL) {
        is_palindrome = true;
    }

    return is_palindrome;
}
