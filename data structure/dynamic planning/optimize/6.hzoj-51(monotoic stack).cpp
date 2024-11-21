//https://oj.haizeix.com/problem/51
//optimization:
//1.去除冗余状态
//2.状态重定义
//3.优化转移过程

/*
properties of the monotonic stack :
维护最近的最大和最小值
2
|
4
3
2
1
3

从左往右遍历: 被弹出的元素右侧第一个小于他的值都为2
未被弹出的元素入栈的元素左侧第一个小于他的值为1
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define MAX_N 1000
int dp[MAX_N+5];
int f[MAX_N+5][MAX_N+5];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&f[i][j]);
        }
    }
    for(int i = n - 1; i >= 0;i--)
    {
        for(int j = 0;j<m;j++)
        {
            if(f[i][j]  == 0) continue;
            f[i][j] += f[i+1][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        stack<int> s;
        f[i][m] = -1;
        s.push(m);
        for(int j=m-1;j>=0;j--)
        {
            while(!s.empty() && f[i][s.top()] >= f[i][j]) s.pop();
            dp[j] = f[i][j] * (s.top() - j) + dp[s.top()];
            ans+=dp[j];
            s.push(j);
        }
    }
    cout<<ans%100007<<endl;
    return 0;
}