//https://oj.haizeix.com/problem/52

//dp[i] = min(dp[j] + sum[j]^2 - 2sum[i]sum[j] + sum[i]^2 + M)
/*
    确定值和混合值并存

*/
#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 1000000
typedef long long ll;
#define Y(j) (dp[j] + (sum[j]*sum[j]))
#define K(i,j) (1.0*(Y(i)-Y(j))/(sum[i]-sum[j]))
ll dp[MAX_N+5] = {0};
int main()
{
    int n,M;
    cin>>n>>M;
    vector<ll> sum(n+1,0);
    deque<ll> q;
    for(int i=1;i<=n;i++)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    q.push_back(0);
    for(int i=1;i<=n;i++)
    {
        while(q.size() >= 2 && K(q.front(),*(q.begin()+1)) <= 2*sum[i]) q.pop_front();
        dp[i] = Y(q.front()) - 2*sum[i]*sum[q.front()] + sum[i]*sum[i] + M;
        while(q.size()>=2 && K(q.back(),i) < K(*(q.end()-2),q.back())) q.pop_back();
        q.push_back(i);
    }
    cout<<dp[n]<<endl;
    return 0;
}