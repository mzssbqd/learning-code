#include<iostream>
using namespace std;
#define MAX_V 10000
int dp[MAX_V+5]={0};
//dp(j)=max(dp[j],dp[j-v]+w);//没有更新的dp[j]和已经更新的dp[j-v]+w
int main()
{
    int n,V;
    cin>>n>>V;
    for(int i=1,v,w;i<=n;i++)
    {
        cin>>v>>w>>s;
        for(int j=v;j<=V;j++)
        {
            dp[j]=max(dp[j],dp[j-v]+w);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}