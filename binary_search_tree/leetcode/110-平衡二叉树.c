/*************************************************************************
	> File Name: 110-平衡二叉树.c
	> Author: 
	> Mail: 
	> Created Time: 六  9/22 14:49:48 2018
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int depth(struct TreeNode *root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return depth(root->left) > depth(root->right) ? depth(root->left) + 1 : depth(root->right) + 1;
}
bool isBalanced(struct TreeNode *root) {
    if(root == NULL){
        return true;
    }
    if (!isBalanced(root->left)) return false;
    if (!isBalanced(root->right)) return false;
    int dif = depth(root->left) - depth(root->right);
    if(dif > 1 || dif < -1){
        return false;
    }else{
        return true;
    }
}
