/*************************************************************************
	> File Name: 5.find_target.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 17:27:24 2018
 ************************************************************************/
//面试算法题：在矩阵中查找一个数字
#include <stdio.h>
#include <stdlib.h>
int find_target(int ** matrix, int n, int m, int target) {
	if (target > matrix[n - 1][m - 1]) return 0;
    int i;
    int left, right, mid;
    left = 0; right = n - 1;
    // 第一次二分，找到第一个行尾元素大于 target 的行号
    while (left < right) {
        mid = (left + right) >> 1;
        if (matrix[mid][m - 1] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    i = left; // 将找到的行号存储在 i 中
    left = 0; right = m - 1;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (matrix[i][mid] == target) return 1;
        if (matrix[i][mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int ** v;
	v = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < m; ++i) {
		v[i] = (int*)malloc(m * sizeof(int));
	}
	int tp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j){
			scanf("%d", &v[i][j]);
		}
	}
	int tot;
	scanf("%d", &tot);
	for (int i = 0; i < tot; ++i) {
		scanf("%d", &tp);
		if (find_target(v, n, m, tp)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}

