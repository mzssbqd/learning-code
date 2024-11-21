#include<iostream>
using namespace std;
#define MAX_N 1000
int val[MAX_N+5][MAX_N+5];
int dp[MAX_N+5][MAX_N+5];

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j=1;j<=i;j++)
        cin>>val[i][j];
    }
    dp[1][1]=val[1][1];
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=i-1;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+val[i][j];
        }
        dp[i][1]=dp[i-1][1]+val[i][1];
        dp[i][i]=dp[i-1][i-1]+val[i][i];
    }
    int ans=dp[n][1];
    for(int i=2;i<=n;i++)
    {
        ans=max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}