/*
1.合法坐标判断:
在原有地图的外围,放一圈0,代表不能行走的点
2.判断当前路径不重复:
将走过的地方标记为0
3.障碍判断:
障碍为0
    0 0 0 0
    0 1 1 0
    0 1 1 0
    0 0 0 0
*/

#include<iostream>
using namespace std;

#define MAX_N 5

int g[MAX_N+5][MAX_N+5] = {0};

int dir[4][2] = {{0,1} , {1,0} ,{-1,0} , {0,-1}};

int cnt = 0;
void dfs(int x,int y,int a,int b)
{
    if(x == a && y == b)
    {
        cnt += 1;
        return;
    }
    g[x][y] = 0;
    for(int i = 0;i < 4;i++)
    {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if(g[dx][dy] == 0) continue;
        dfs( dx, dy, a, b);
    }
    g[x][y] = 1;
    return; 
}
int main()
{
    int n,m,t,x,y,a,b;
    cin>>n>>m>>t>>x>>y>>a>>b;
    for(int i=1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            g[i][j] = 1;
        }
    }
    for(int i=0,k,p;i<t;i++)
    {
        cin>>k>>p;
        g[k][p] = 0;
    }
    dfs(x , y, a, b);
    cout<< cnt <<endl;
    return 0;
}

