/*************************************************************************
	> File Name: 1-马踏过河卒.c
	> Author: 
	> Mail: 
	> Created Time: 六  9/ 8 15:57:56 2018
 ************************************************************************/

#include <stdio.h>
int map[21][21];
long long f[21][21];
int dir[9][2] = {{0,0}, {1, 2}, {2, 1}, {-1, 2}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}, {2, -1}};
	

long long numberOfPaths(int BX, int BY, int CX, int CY) {
	f[0][0] = 1;
    for(int i = 0; i <= BX; i++){
        for(int j = 0; j <= BY; j++){
            map[i][j] = 1;
        }
    }
    int x, y;
    for(int i = 0; i < 9; i++){
    	x = CX + dir[i][0];
        y = CY + dir[i][1];
        if(x < 0 || x > BX)continue;
        if(y < 0 || y > BY)continue;
        map[x][y] = 0;
    }
    for(int i = 0; i <= BX; i++){
        for(int j = 0; j <= BY; j++){
            if(i!= 0 && j!= 0){
                f[i][j] = 0;
            }
            if(!map[i][j])continue;
            if(i!= 0 && map[i - 1][j]){
            	f[i][j] += f[i - 1][j];
            }
            if(j!= 0 && map[i][j - 1]){
                f[i][j] += f[i][j - 1];
            }
        }
    }
    return f[BX][BY];
    
}
int main() {
	int cx, cy;
	int n, m;
	scanf("%d %d %d %d", &n, &m, &cx, &cy);
	printf("%lld\n", numberOfPaths(n, m, cx, cy));
    return 0;
}

