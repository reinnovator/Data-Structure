/*************************************************************************
	> File Name: 100.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/25 16:46:46 2018
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
        return true;
    else
        return false;
}