/*************************************************************************
	> File Name: 104-求二叉树的最大深度.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 14:44:06 2018
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    return (ld > rd ? ld : rd) + 1;
   
}
