/*************************************************************************
	> File Name: 669-修剪平衡二叉搜索树.c
	> Author: 
	> Mail: 
	> Created Time: 六  9/22 14:50:54 2018
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    if(!root)
        return NULL;
    if(root->val < L){
        return trimBST(root->right, L, R);
    }
    if(root->val > R){
        return trimBST(root->left, L, R);
    }
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}


