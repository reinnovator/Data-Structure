/*************************************************************************
	> File Name: 4.get_two_sum.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 17:14:31 2018
 ************************************************************************/
//从数组numbers中找到两个数，两个数相加的和等于target
#include <stdio.h>
int* get_two_sum(int *numbers, int length, int target) {
	int *ans = (int *)malloc(sizeof(int) * 2);
    int ind1, ind2;
    ind1 = 0;
    ind2 = length - 1;
    while (ind1 < ind2) {
        if (numbers[ind1] + numbers[ind2] == target) break;
        if (numbers[ind1] + numbers[ind2] < target) {
            ++ind1;
        } else {
            --ind2;
        }
    }
    if (ind1 < ind2) {
        ans[0] = ind1;
        ans[1] = ind2;
    }
    return ans;
}
int main() {
	int n;
	int v[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	int x;
	scanf("%d", &x);
	int* ans = get_two_sum(v, n, x);
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}
