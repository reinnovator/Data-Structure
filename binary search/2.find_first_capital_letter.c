/*************************************************************************
	> File Name: 2.find_first_capital_letter.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 16:07:27 2018
 ************************************************************************/
//找到第一个大写字母
#include <stdio.h>
#include <string.h>
int find_first_capital_letter(char *str, int len) {
    int mid, left, right;
	right = len - 1; 
    left = 0;
    while(left < right){
        mid = (left + right) / 2;
        if(is_upper(str[mid])){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}
int is_upper(char *str){
    return str >= 'A' && str <= 'Z';
}
int main() {
    char str[100000+5];
    scanf("%s", str);
    int sum = 0;
    int len = strlen(str);
    for (int i = 0; i < 100000; ++i) {
        int x = find_first_capital_letter(str, len);
        sum += x;
    }
    printf("%d\n", find_first_capital_letter(str, len));
    return 0;
}

