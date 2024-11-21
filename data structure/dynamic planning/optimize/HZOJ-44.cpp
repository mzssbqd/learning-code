#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_N 1000000
vector<int> len(MAX_N+5);//只能赋值0
int dp[MAX_N+5]={0};
int main()
{
    int n;
    cin>>n;
    int ans=0;
    len[0]=-1;
    for(int i=1,a;i<=n;i++)
    {
        cin>>a;
        dp[i]=(lower_bound(len.begin()+1,len.begin()+ans+1,a)-len.begin());
        len[dp[i]]=a;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}