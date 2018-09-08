/*************************************************************************
	> File Name: 2-杨辉三角.c
	> Author: 
	> Mail: 
	> Created Time: 六  9/ 8 16:50:02 2018
 ************************************************************************/
#include <stdio.h>
long long PascalTriangle(int row, int column) {
    long long **arr = (long long **)malloc(2 * sizeof(long long *));
    arr[0] = (long long *)calloc(row, sizeof(long long));
    arr[1] = (long long *)calloc(row, sizeof(long long));
    arr[1][0] = 1;
    int i, j;
    for (i = 2; i <= row; ++i) {
        for (j = 0; j < i; ++j) {
            arr[i % 2][j] = arr[(i % 2) ^ 1][j];
            if (j > 0) {
                arr[i % 2][j] += arr[(i % 2) ^ 1][j - 1];
            }
        }
    }
    long long ret = arr[row % 2][column - 1];
    free(arr[0]);
    free(arr[1]);
    free(arr);
    return ret;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%lld\n", PascalTriangle(n, m));
	return 0;
}
