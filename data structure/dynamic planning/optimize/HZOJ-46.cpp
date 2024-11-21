#include<iostream>
#include<string.h>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAX_N 1000
char a[MAX_N+5];
int dp[MAX_N+5][MAX_N+5];
int main()
{
    scanf("%s",a+1);
    int n=strlen(a+1);
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            if(a[i]==a[j] && dp[i+1][j-1]==0)
            {
                dp[i][j]=0;
            }
            else 
            {
                dp[i][j]=l;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}