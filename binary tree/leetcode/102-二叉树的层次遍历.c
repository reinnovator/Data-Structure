/*************************************************************************
	> File Name: 102.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 14:26:15 2018
 ************************************************************************/

#include<stdio.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int max_depth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int ld = max_depth(root->left);
    int rd = max_depth(root->right);
    return (ld > rd ? ld : rd) + 1;
}//求二叉树的深度


void calcColumnSizes(struct TreeNode *root, int k, int *arr) {
    if (root == NULL) return ;
    arr[k] += 1;
    calcColumnSizes(root->left, k + 1, arr);
    calcColumnSizes(root->right, k + 1, arr);
    return ;
}//递归求每层的个数存到sizes




void fetch_result(struct TreeNode *root, int k, int *ind, int **ret) {
    if (root == NULL) return ;
    ret[k][ind[k]++] = root->val;
    fetch_result(root->left, k + 1, ind, ret);
    fetch_result(root->right, k + 1, ind, ret);
    return ;
}//按层记录节点值



int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int depth = max_depth(root);
    int *sizes = (int *)calloc(depth, sizeof(int));
    calcColumnSizes(root, 0, sizes);    
    int **ret = (int **)malloc(sizeof(int *) * depth);
    for (int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * sizes[i]);
        sizes[i] = 0;//将size设为0可以节省一个数组空间
    }
    fetch_result(root, 0, sizes, ret);
    *columnSizes = sizes;
    *returnSize = depth;
    return ret;
}


