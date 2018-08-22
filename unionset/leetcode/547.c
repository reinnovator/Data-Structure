/*************************************************************************
	> File Name: 547.c
	> Author: 
	> Mail: 
	> Created Time: 三  8/22 23:53:15 2018
 ************************************************************************/

struct DisjointSet{
    int par;
    int rank;
};
#define maxn 222
struct DisjointSet ds[maxn];

void init()
{
    for(int i = 0;i < maxn;i++){
        ds[i].par = i;
        ds[i].rank = 1;
    }
}

int find(int x)
{
    if(x == ds[x].par) return  x;
    return ds[x].par = find(ds[x].par);
}

void _union(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return ;
    if(ds[x].rank < ds[y].rank)
        ds[x].par = y;
    else{
        if(ds[x].rank == ds[y].rank)
            ds[x].rank++;
        ds[y].par = x;
    }
}

int same(int x, int y)
{
    return find(x) == find(y);
}

int findCircleNum(int** M, int MRowSize, int MColSize) {
    init();
    for(int i = 0;i < MRowSize;i++){
        for(int j = i + 1;j < MColSize;j++){
            if(M[i][j] && M[j][i]) _union(i,j);
        }
    }
    int count = 0;
    for(int i = 0;i < MRowSize;i++){
        if(ds[i].par == i) count++;
    }
    return count;
}
