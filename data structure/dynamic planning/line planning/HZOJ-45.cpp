#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define MAX_N 1000
char a[MAX_N+5],b[MAX_N+5];
int dp[MAX_N+5][MAX_N+5];
int main()
{
    scanf("%s %s",&a+1,&b+1);
    int n=strlen(a+1),m=strlen(b+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]) 
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}