//背包优化
//https://oj.haizeix.com/problem/49


/*
1.
dp[i] dp[i-v*n]+w*n
i%v=(i-v*n)%v

dp[7]:  dp[7] dp[2]+6
dp[12] : dp[12] dp[7]+6 dp[2]+12 
{dp[12]比dp[7]各项多6}
只要减去一个偏移量,就可以利用pd[7]中最大值来轻松推导出dp[12]中的最大值(单调队列中压入dp[12]即可)
*/
#include<iostream>
#include<deque>
using namespace std;
#define MAX_V 100000
int dp[105][MAX_V+5]={0};
int main()
{
    int V,n;
    cin>>V>>n;
    for(int i=1,v,w,s;i<=n;i++)
    {
        cin>>v>>w>>s;
        for(int r=0;r<v;r++)
        {
            deque<int> q;
            for(int j=r;j<=V;j+=v)
            {
                dp[i-1][j]-=j/v*w;
                while(!q.empty() && dp[i-1][q.back()]<dp[i-1][j]) q.pop_back();
                q.push_back(j);
                if((j-q.front())/v>s)q.pop_front();
                dp[i][j]=dp[i-1][q.front()]+j/v*w;
            }
        }
    }
    cout<<dp[n][V]<<endl;
    return 0;
}