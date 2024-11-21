#include<bits/stdc++.h>
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
    for(int i = 1;i <= n; i++) dp[n][i]=val[n][i];
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+val[i][j];
        }
    }
    cout<<dp[1][1]<<endl;
    return 0;
}