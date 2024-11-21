
/*
1.最短步长
bfs(层序遍历) : 适合求最短步长的问题
*/

#include<iostream>
#include<queue>
using namespace std;

#define MAX_N 400
int dis[MAX_N+5][MAX_N+5];

int dir[8][2] = {
    {1,2} , {2,1},
    {-1,2}, {-2,1},
    {1,-2}, {2,-1},
    {-1,-2}, {-2,-1}
};
struct Data
{
    Data() {}
    Data(int x1,int y1,int dis1):x(x1),y(y1),dis(dis1) {}
    int x,y,dis;
};
void bfs(int x,int y,int n,int m)
{
    int dx,dy;
    Data now;
    queue<Data> q;
    q.push(Data(x,y,0));
    dis[x][y] = 0;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for(int i = 0;i < 8; i++)
        {
            dy = now.y + dir[i][0];
            dx = now.x + dir[i][1];
            if(dy < 1 || dy > m) continue;
            if(dx < 1 || dx > n) continue;
            if(dis[dx][dy] != -1) continue;
            q.push(Data(dx,dy,now.dis + 1));
            dis[dx][dy] = now.dis + 1; //需要立马更新dis,因为需要利用dis来判断是否需要执行
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
    bfs( x, y, n, m);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            printf("%d ",dis[i][j]);
        }
        printf("\n");
    }

    return 0;
}