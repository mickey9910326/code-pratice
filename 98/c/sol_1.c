/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leeetcode 98. Validate Binary Search Tree
 * @date 2020.12.22
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <stdbool.h>

/**
 * @brief Determine whether the binary tree 'p' is a valid BST.
 *
 * BST is abbreviation of binary search tree.
 *
 * @param root Root of a binary tree.
 * @return true The tree is a valid BST.
 * @return false The tree is not a valid BST.
 */
bool isValidBST(struct TreeNode* root) {
    int size = tree_size(root);
    int* arr = malloc(sizeof(int) * size);
    tree_sort(root, arr);

    for (int i = 1; i < size; i++) {
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Get the size of a binary tree.
 *
 * @param root Root of a binary tree.
 * @return int Size of the tree.
 */
int tree_size(struct TreeNode* root) {
    int sz = 0;
    tree_size_help(root, &sz);
    return sz;
}

/**
 * @brief Help function of tree_size.
 *
 * Use in-order recursive method to interative.
 *
 * @param p Current node of tree.
 * @param sz_p Pointer of size to return.
 */
void tree_size_help(struct TreeNode* p, int* sz_p) {
    if (!p) {
        return;
    }
    (*sz_p)++;
    tree_size_help(p->left, sz_p);
    tree_size_help(p->right, sz_p);
    return;
}

/**
 * @brief Sort all value of node in a binary tree to a given array.
 *
 * @param root Root of a binary tree.
 * @param arr Array to put value of node.
 */
void tree_sort(struct TreeNode* root, int* arr) {
    int idx = 0;
    tree_sort_help(root, arr, &idx);
    return;
}

/**
 * @brief Help function of tree_sort.
 *
 * Use in-order recursive method to interative.
 *
 * @param p Current node of tree.
 * @param arr Pointer of array to return.
 * @param idx_p Pointer of current index of 'arr'.
 */
void tree_sort_help(struct TreeNode* p, int* arr, int* idx_p) {
    if (!p) {
        return;
    }
    tree_sort_help(p->left, arr, idx_p);
    arr[*idx_p] = p->val;
    (*idx_p)++;
    tree_sort_help(p->right, arr, idx_p);
    return;
}
