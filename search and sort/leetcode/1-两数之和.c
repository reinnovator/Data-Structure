/*************************************************************************
	> File Name: 1-两数之和.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 17:05:34 2018
 ************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
        int *result = (int *)malloc(2 * sizeof(int));
        for (int i = 0; i < numsSize - 1; i++) {
            int v = target - nums[i];
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] == v ){
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
    return result;
}


