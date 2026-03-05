/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkAVL(struct TreeNode *root, long long min, long long max) {
    if (root == NULL) {
        return 0;
    }

    if (root->val <= min || root->val >= max) {
        return -1;
    }

    int left = checkAVL(root->left, min, root->val);
    int right = checkAVL(root->right, root->val, max);

    if (left == -1 || right == -1) {
        return -1;
    }

    if (abs(left - right) > 1) {
        return -1;
    }

    return 1 + (left > right ? left : right);

}
bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    return checkAVL(root, LLONG_MIN, LLONG_MAX) != -1;
}
