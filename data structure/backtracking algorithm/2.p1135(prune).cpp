//source: https://www.luogu.com.cn/problem/P1135

/*
1.剪枝(prune): 
history answers pruning:
no need to search for branchs that are larger than the current minimum branch

*/

#include<iostream>
using namespace std;

#define MAX_N 200
int to[MAX_N + 5],dis[MAX_N + 5];

void dfs(int k,int a,int n)
{
    if(dis[a] <= k) return;
    dis[a] = k;
    if(a + to[a] <= n) dfs(k+1,a + to[a],n);
    if(a - to[a] >= 1) dfs(k+1,a - to[a],n);
    return;
}
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i = 1; i <=n; i++) 
    {
        cin>>to[i];
        dis[i] = 0x7FFFFFFF;
    }
    dfs(0 , a ,  n);
    if(dis[b] == 0x7FFFFFFF) cout<<-1<<endl;
    else cout<<dis[b]<<endl;
    return 0;
}