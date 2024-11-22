//https://www.luogu.com.cn/problem/P1019

/*
1.预处理:

2.维护单词使用次数:vis map

3.
*/

#include<iostream>
#include<string>
using namespace std;

#define MAX_N 20
string s[MAX_N + 5];

int d[MAX_N + 5][MAX_N + 5];

int vis[MAX_N] = {0};

int __sup(string& s1 ,string& s2)
{
    for(int i = s1.size() -1; i >= 1;i--)
    {
        int flag = 1;
        for(int j = 0 ;i + j < (int)s1.size();j++)
        {
            if(s1[i + j] == s2[j]) continue;
            flag = 0;
            break;
        }
        if(flag == 1) return s1.size() - i;
    }
    return 0;
}

long long ans = 0;
void dfs(int a,long long l,int n)
{
    ans = max(ans, l);
    vis[a] +=1;
    for(int i = 1;i <= n;i++)
    {
        if(d[a][i] == 0) continue; // 拼接顺序
        if(vis[i] == 2) continue;
        dfs(i ,l + s[i].size() - d[a][i], n);
    }
    vis[a] -=1;
    return;
}

int main()
{
    int n;
    char a;
    cin>>n;
    for(int i = 1;i <= n; i++)
    {
        cin>>s[i];
    }
    cin>>a;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            d[i][j] = __sup(s[i] , s[j]);
        }
    }
    for(int i = 1; i <= n;i++)
    {
        if(s[i][0] != a) continue;
        dfs(i , s[i].size() ,n);
    }
    cout<< ans <<endl;
    return 0;
}