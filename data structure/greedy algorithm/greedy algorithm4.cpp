#include<iostream>
#include<cinttypes>
using namespace std;
#define MAX_N 100
int arr[MAX_N+5][MAX_N+5]={0};
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            arr[i][j]+=arr[i-1][j];
        }
    }
    int ans=INT32_MIN;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int num=0;
            for(int k=1;k<=n;k++)
            {
                int a=arr[j][k]-arr[i-1][k];
                if(num>=0) num+=a;
                else num=a;
                if(num>ans) ans=num;
            }
            
        }
    }
    std::cout<<ans<<endl;
    return 0;
}