/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1367. Linked List in Binary Tree
 * @date 2021.05.12
 *
 * method: DFS of DFS (recursive)
 *
 * Time Complexity: O(k*n)
 * Space Complexity: O(k*h)
 *
 * k is length of list
 * n is num of nodes in tree
 * h is height of tree
 *
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

bool compare_dfs(struct ListNode* head, struct TreeNode* root) {
    if (!head) {
        return true;
    }

    if (root == NULL) {
        return false;
    }

    if (root->val != head->val) {
        return false;
    }

    bool metched_l = compare_dfs(head->next, root->left);
    bool metched_r = compare_dfs(head->next, root->right);
    return metched_l || metched_r;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (head == NULL) {
        return true;
    }

    if (root == NULL) {
        return false;
    }

    if (compare_dfs(head, root)) {
        return true;
    }

    bool metched_l = isSubPath(head, root->left);
    bool metched_r = isSubPath(head, root->right);
    return metched_l || metched_r;
}

