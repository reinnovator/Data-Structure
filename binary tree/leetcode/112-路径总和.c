/*************************************************************************
	> File Name: 112-路径总和.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 15:19:17 2018
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root) return false;
   
    if (!root->left && !root->right) return root->val == sum;
    int destination_sum = sum - root->val;
    if(hasPathSum(root->left, destination_sum) == true)
        return true;
    
    if(hasPathSum(root->right, destination_sum) == true)
        return true;
    
    return false;
}
