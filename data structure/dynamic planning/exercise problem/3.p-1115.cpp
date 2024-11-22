#include<iostream>
using namespace std;
int main()
{
    int n,dp = 0,a,sum=-10000000;
    cin>>n;
    while(n--)
    {
        cin>>a;
        dp=max(dp+a,a);
        sum=max(sum,dp);
    }
    cout<<sum<<endl;
    return 0;
}