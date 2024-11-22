//https://www.luogu.com.cn/problem/P1433

/*
1.排列形枚举
    状态压缩优化
2.最小路径
    搜索剪枝优化
3.预处理两点之间距离
*/

#include<iostream>
#include<math.h>
#include<unordered_map>
using namespace std;

#define MAX_N 20
#define lowbit(x) ((x) & (-x))

double x[MAX_N+5],y[MAX_N+5];

double dis[MAX_N+5][MAX_N+5];

double dp[70000][MAX_N + 5];

unordered_map<int,int> m;

double __dis(int i ,int j)
{
    return sqrt(pow(x[i]-x[j],2) + pow(y[i] - y[j],2));
}

double ans = 0x3f3f3f3f3f;
void dfs(int mask,int now,double sum)
{
    if(!mask)
    {
        ans = min(ans,sum);
        return;
    }
    for(int i = mask; i; i -= lowbit(i))
    {
        int ind = m[lowbit(i)] ,next_t = mask ^ (1 << ind);
        double l = dp[mask][now] + dis[now][ind];
        if(dp[next_t][ind] != 0 && dp[next_t][ind] <= l) continue;
        dp[next_t][ind] = l;
        if(ans <= l) continue;
        dfs(next_t , ind ,l);
    } 
    return;
}
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 0;i <= n;i++)
    {
        for(int j = i + 1;j <= n; j++)
        {
            dis[i][j] = dis[j][i] = __dis(i , j);
        }
    }   
    for(int i = 0;i <= n;i++) m[1 << i] = i;
    dfs((1 << (n + 1)) -2, 0, 0);
    printf("%.2lf",ans);
    return 0;
}