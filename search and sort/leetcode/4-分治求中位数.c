/*************************************************************************
	> File Name: 4-分治求中位数.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 19:19:01 2018
 ************************************************************************/

int getkth(int s[], int m, int l[], int n, int k){
        //确保m < n 
        if (m > n) 
            return getkth(l, n, s, m, k);
        if (m == 0)
            return l[k - 1];
        if (k == 1)
            return s[0] > l[0] ? l[0]: s[0];
	//递归过程
        int i = m > k / 2 ? k / 2 : m, j = n > k / 2 ? k / 2 : n;
        if (s[i - 1] > l[j - 1])
            return getkth(s, m, l + j, n - j, k - j);
        else
            return getkth(s + i, m - i, l, n, k - i);
        return 0;
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        //总长度的一半
        int l = (m + n + 1) / 2;
        int r = (m + n + 2) / 2;
        return (getkth(A, m ,B, n, l) + getkth(A, m, B, n, r)) / 2.0;
    }
