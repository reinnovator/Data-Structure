/*************************************************************************
	> File Name: 235-二叉搜索树的最近公共祖先.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 15:47:58 2018
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
      if (root == NULL)
            return root;

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right,p,q);
        } else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
}
