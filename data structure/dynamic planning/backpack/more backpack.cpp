#include<iostream>
using namespace std;
//#define MAX_N 100
#define MAX_V 10000
//int v[MAX_N+5],w[MAX_N+5];
int dp[MAX_V+5]={0};//n:thing v:value 
int main()
{
    int V,n;
    cin>>V>>n;

    for(int i=1,v,w,s;i<=n;i++)
    {
        cin>>v>>w>>s;
        for(int j=V;j>=v;j--)
        {
            for(int k=1; k<=s && j-v*k>=0;k++)
            {
                dp[j]=max(dp[j],dp[j-v*k]+w*k);
            }
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}   