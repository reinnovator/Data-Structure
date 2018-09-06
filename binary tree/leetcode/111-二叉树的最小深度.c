/*************************************************************************
	> File Name: 111-二叉树的最小深度.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 15:33:53 2018
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (NULL == root)
        return 0;
     int l = minDepth(root->left);
     int r = minDepth(root->right);
     if (!l)
         return r+1;
     if (!r)
         return l+1;
     return (l<r)?l+1:r+1;
}
