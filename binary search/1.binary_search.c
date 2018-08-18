/*************************************************************************
	> File Name: 1.binary_search.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 15:37:49 2018
 ************************************************************************/

#include<stdio.h>
int binary_search(int target, int *num, int len) {
	int left, right, mid;
    left = 0;
    right = len - 1;
    while(left <= right) {
        mid = (left + right) >> 1;
        if(num[mid] == target){
            return mid;
        }
        if(num[mid] > target) {
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}
int main() {
	int num[1000000];
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int value;
		scanf("%d", &value);
		printf("%d\n", binary_search(value, num, n));
	}
	return 0;
}
