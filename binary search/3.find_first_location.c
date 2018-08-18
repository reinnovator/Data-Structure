/*************************************************************************
	> File Name: 3.find_first_location.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 17:04:39 2018
 ************************************************************************/
#include <stdio.h>
int find_first_location(int *num, int len, int target) {
	 int left, right, mid;
    if (target <= num[0]) return 0;
    left = 0; right = len - 1;
    while (left < right) {
        mid = (left + right + 1) >> 1;
        if (num[mid] < target) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left + 1;
}
int main() {
	int num[100000];
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int value;
		scanf("%d", &value);
		printf("%d\n", find_first_location(num, n, value));
	}
	return 0;
}

