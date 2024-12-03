#include<iostream>
using namespace std;
#define MAX_V 10000
int dp[MAX_V+5];
int main()
{
    int V,n;
    cin>>V>>n;
    for(int i=1,v,w;i<=n;i++)
    {
        cin>>v>>w;
        for(int j=V;j>=v;j--)
        {
            dp[j]=max(dp[j],dp[j-v]+w);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}   