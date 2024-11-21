#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,temp=0;
    cin>>n;
    vector<vector<int>> arr(n+1,vector<int>(n+1,0));
    int ans=0;
    int len=0;
    for(int i=1;i<=n;i++)
    {
        int j=1;
        for(;j<=n;j++)
        {
            temp=0;
            cin>>arr[i][j];
            temp+=arr[i][j];
            arr[i][j]+=arr[i-1][j];
        }
        if(temp>ans)
        {
            ans=temp;
            len=arr[i][j]-arr[i-1][j];
        }
    }
    int max=0,j=1;
    for(int i=n,j=1;j<=n;j++)
    {
        if(arr[i][j]>arr[i][max]) max=j;
    }
    max=arr[n][j]+ans-len;
    cout<<max<<endl;
    return 0;
}