/*************************************************************************
	> File Name: 107-二叉树倒序层次遍历.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 14:40:47 2018
 ************************************************************************/
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
int maxDepth (struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    return (ld > rd ? ld : rd) + 1;
}

void every_nums(struct TreeNode *root, int k, int *arr) {
    if (root == NULL) {
        return ;
    }
    arr[k] += 1;
    every_nums(root->left, k + 1, arr);
    every_nums(root->right, k + 1, arr);
}

void fetch_result(struct TreeNode *root, int k, int **ret, int *size, int depth) {
    if (root == NULL) {
        return ;
    }
    ret[depth - k - 1][size[depth - k - 1]++] = root->val;
    fetch_result(root->left, k + 1, ret, size, depth);
    fetch_result(root->right, k + 1, ret, size, depth);
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int depth = maxDepth(root);
    int *size = (int *)malloc(sizeof(int) * depth);
    memset(size, 0, sizeof(int) * depth);
    every_nums(root, 0, size);
    int **ret = (int **)malloc(sizeof(int *) * depth);
    for (int i = 0; i < depth; ++i) {
        ret[i] = (int *)malloc(sizeof(int) * size[depth - i - 1]);
        size[depth -i - 1] = 0;
    }
    fetch_result(root, 0, ret, size, depth);
    *returnSize = depth;
    *columnSizes = size;
    return ret;
}

