
/*
core point:
1.方向数组(directional array) : 记录偏移量
2.历史答案剪枝
*/

#include<iostream>
using namespace std;

#define MAX_N 400
typedef long long ll;
ll dis[MAX_N+5][MAX_N+5];

int dir[8][2] = {
    {1,2} , {2,1},
    {-1,2}, {-2,1},
    {1,-2}, {2,-1},
    {-1,-2}, {-2,-1}
};
void dfs(int k, int x,int y,int n,int m)
{
    if(dis[x][y] !=-1 && dis[x][y] <= k)
    {
        return;
    }
    dis[x][y] = k;
    //directional array
    for(int i=0;i<8;i++)
    {
        if(x + dir[i][0] <=n && y + dir[i][1]<=m){
            dfs(k+1 , x + dir[i][0] , y + dir[i][1] , n , m);
        }
    }
    return;
}
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            dis[i][j] = -1;
        }
    }
    dfs( 0, x, y, n, m);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            printf("%lld ",dis[i][j]);
        }
        printf("\n");
    }

    return 0;
}