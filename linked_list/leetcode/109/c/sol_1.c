/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 109. Convert Sorted List to Binary Search Tree
 * @date 2021.05.03
 *
 * Time Complexity: O(nlog(n))
 * Space Complexity: O(log(n))
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

// struct ListNode {
//     int val;
//     struct ListNode* next;
// };

// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

struct TreeNode* treenode_create(int val) {
    struct TreeNode* p = malloc(sizeof(struct TreeNode));
    p->val = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return treenode_create(head->val);
    }

    struct ListNode* prev = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) {
        prev->next = NULL;
    }

    struct TreeNode* root = treenode_create(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}
