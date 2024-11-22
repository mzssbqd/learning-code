#include<iostream>
using namespace std;
#define MAX_N 5000
int dp[MAX_N+5],arr[MAX_N+5];
int main()
{
    int n;
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        dp[i] = 1;
        cin>>arr[i];
        for(int j=1;j<i;j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        sum = max(sum,dp[i]);
    }
    cout<<sum<<endl;
    return 0;
}