/*************************************************************************
	> File Name: 4-取数字.c
	> Author: 
	> Mail: 
	> Created Time: 六  9/ 8 18:16:08 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int pickMaxSum(int **nums, int length) {
	 int i, j;
    for (i = length - 2; i >= 0; --i) {
        for (j = 0; j <= i; ++j) {
            if (nums[i + 1][j] < nums[i + 1][j + 1]) {
                nums[i][j] += nums[i + 1][j + 1];
            } else {
                nums[i][j] += nums[i + 1][j];
            }
        }
    }
    return nums[0][0];
}
int main() {
	int n;
	scanf("%d", &n);
	int **a = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i) {
		a[i] = malloc(sizeof(int) * (i + 1));
		for (int j = 0; j <= i; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d\n", pickMaxSum(a, n));
	return 0;
}
