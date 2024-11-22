#include<iostream>
using namespace std;
#define MAX_N 1000
long long dp[MAX_N+5][MAX_N+5];
int main()
{
    int n,x;
    cin>>n>>x;
    for(int i=1,l,w,u;i <= n;i++)
    {
        cin>>l>>w>>u;
        dp[i][0] += dp[i-1][0];
        for(int j=0;j<=x;j++)
        {
            if(j >= u) dp[i][j] = max(dp[i-1][j-u] + w,dp[i-1][j] + l);
            else dp[i][j] = dp[i-1][j] + l;
        }
    }
    cout<< 5*dp[n][x]<<endl;
    return 0;
}