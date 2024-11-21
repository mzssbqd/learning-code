#include<iostream>
#include<math.h>
using namespace std;
int val[9][9]={0};
int dp[15][10][10][10][10]={0};//dp[n][i][j][x][y]
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            scanf("%d",&val[i][j]);
            val[i][j]+=val[i-1][j]+val[i][j-1]-val[i-1][j-1];
        }
    }
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            for(int x=i;x<=8;x++)
            {
                for(int y=j;y<=8;y++)
                {
                    dp[1][i][j][x][y]=pow(val[x][y]-val[x][j-1]-val[i-1][y]+val[i-1][j-1],2);
                }
            }
        }
    }
    for(int t=2;t<=n;t++)
    {
        for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            for(int x=i;x<=8;x++)
            {
                for(int y=j;y<=8;y++)
                {
                    int ans=0x3f3f3f3f;
                    for(int c=j;c<y;c++)
                    {
                        int val1=dp[1][i][j][x][c]+dp[t-1][i][c+1][x][y];
                        int val2=dp[t-1][i][j][x][c]+dp[1][i][c+1][x][y];
                        ans=min(ans,min(val1,val2));
                    }
                    for(int c=i;c<x;c++)
                    {
                        int val3=dp[1][i][j][c][y]+dp[t-1][c+1][j][x][y];
                        int val4=dp[t-1][i][j][c][y]+dp[1][c+1][j][x][y];
                        ans=min(ans,min(val3,val4));
                    }
                    dp[t][i][j][x][y]=ans;
                }
            }
        }
    }
    }
    
    printf("%d",dp[n][1][1][8][8]);
    return 0;
}