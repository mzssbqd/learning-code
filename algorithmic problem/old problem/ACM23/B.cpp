#include<iostream>
using namespace std;
#define MAX_N 1000
int dp[MAX_N+5];
int main()
{
    int n;
    cin>>n;
    dp[0]=0;
    dp[1]=0;
    dp[2]=1000;
    dp[3]=1800;
    for(int i=4;i<=n;i++)
    {
        dp[i]=max(max(dp[i-2]+1000,dp[i-3]+1800),dp[i-4]+2700);
    }
    cout<<dp[n]<<endl;
    return 0;
}