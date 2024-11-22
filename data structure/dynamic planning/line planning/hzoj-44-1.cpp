#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1000000
int dp[MAX_N+5];
map<int,int> m;
int main()
{
    int n,x;
    scanf("%d",&n);
    scanf("%d",&x);
    m.insert(make_pair(0,1));
    m.insert(make_pair(x,1));
    for(int i=2,a,b;i<=n;i++)
    {
        scanf("%d",&a);
        b=(m.lower_bound(a)--)->second;
        dp[i]=b;
        cout<<"test1:"<<dp[i]<<" ";
        m.insert(make_pair(a,dp[i]+1));
    }
    cout<<dp[n]<<endl;
    return 0;
}