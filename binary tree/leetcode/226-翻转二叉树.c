/*************************************************************************
	> File Name: 226-翻转二叉树.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 15:37:25 2018
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* root) {
       if(root == NULL) {
            return NULL;
        }
        struct TreeNode *tempNode = root->left;
        root->left = root->right;
        root->right = tempNode;

        invertTree(root->left);
        invertTree(root->right);

        return root;
}

