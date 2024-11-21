#include<iostream>
using namespace std;
#define MAX_N 40

int val[400],cnt[5]={0};
int dp[2][MAX_N+5][MAX_N+5][MAX_N+5];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    for(int i=1,k;i<=m;i++)
    {
        cin>>k;
        cnt[k]+=1;
    }

    dp[0][0][0][0]=val[1];
    for(int a=0;a<=cnt[1];a++)
    {
        for(int b=0;b<=cnt[2];b++)
        {
            for(int c=0;c<=cnt[3];c++)
            {
                for(int d=0;d<=cnt[4];d++)
                {
                    int ind=a%2,rind=(a-1)%2;
                    int ans=dp[0][0][0][0];
                    int s=1+a+2*b+3*c+4*d;
                    if(a) ans=max(ans,dp[rind][b][c][d]+val[s]);
                    if(b) ans=max(ans,dp[ind][b-1][c][d]+val[s]);
                    if(c) ans=max(ans,dp[ind][b][c-1][d]+val[s]);
                    if(d) ans=max(ans,dp[ind][b][c][d-1]+val[s]);
                    dp[ind][b][c][d]=ans;
                }
            }
        }
    }
    cout<<dp[cnt[1]%2][cnt[2]][cnt[3]][cnt[4]]<<endl;
    return 0;
}