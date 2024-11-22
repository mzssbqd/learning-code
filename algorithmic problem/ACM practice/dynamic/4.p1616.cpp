#include<iostream>
using namespace std;
const int MAX_T = 1000; 
long long dp[MAX_T] = {0};
int main()
{
    int T,m;
    cin>>T>>m;
    for(int i=1,t,v;i<=m;i++)
    {
        scanf("%d %d",&t,&v);
        for(int j = T;j >=t;j--)
        {
                dp[j] = max(dp[j - t] + v, dp[j]);
        }
    }
    cout<<dp[T]<<endl;
    return 0;
}