/*************************************************************************
	> File Name: 110-判断是否为平衡二叉树.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 15:03:45 2018
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth(struct TreeNode* root) {
        if (root == NULL) 
            return 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        if (left_depth == -1 || right_depth == -1 || (left_depth - right_depth > 1) || ( right_depth - left_depth > 1)) 
        return -1;
          return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }
 
    bool isBalanced(struct TreeNode *root) {
        if (root == NULL) return true;
        else return (depth(root) !=-1);
    }
