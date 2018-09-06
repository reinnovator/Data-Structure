/*************************************************************************
	> File Name: 101.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/25 17:09:41 2018
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isSymmetriclr(struct TreeNode* left, struct TreeNode* right){
     if (left == NULL && right == NULL) return true;
     if (left == NULL && right != NULL) return false;
     if (left != NULL && right == NULL) return false;
     if (left->val != right->val) return false;
     if (!isSymmetriclr(left->left, right->right)) return false;
     if (!isSymmetriclr(left->right, right->left)) return false;
     return true;
 }
 
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isSymmetriclr(root->left, root->right);
}
