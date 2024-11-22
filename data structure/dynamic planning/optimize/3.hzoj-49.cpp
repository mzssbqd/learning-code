//背包优化
//https://oj.haizeix.com/problem/49

//dp[j]=max(dp[j],dp[j-v*k]+w*k)
//find a method
//1 2 3
//binary search
//14:1 2 4 7
#include<iostream>
using namespace std;
#define MAX_V 100000
int dp[MAX_V+5]={0};
int main()
{
    int V,n;
    cin>>V>>n;
    for(int i=1,v,w,s;i<=n;i++)
    {
        cin>>v>>w>>s;
        //wrong
        //如果这样写,那么其实我只选择了1 2 4 7 个背包
        //没有覆盖到1,2,3,4,5,6,7...的背包数量
        //所以我们要先写k,再写j
        // for(int j=V;j>=v;j--)
        // {
        //     for(int k=1; s && j-v*k>=0;s-=k,k*=2)
        //     {
        //         k=min(s,k);
        //         dp[j]=max(dp[j],dp[j-v*k]+w*k);
        //     }
        // }
        for(int k=1;s;s-=k,k*=2)
        {
            k=min(k,s);
            for(int j=V;j>=v*k;j--)
            {
                dp[j]=max(dp[j],dp[j-v*k]+w*k);
            }
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}   