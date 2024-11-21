#include<iostream>
using namespace std;
#define MAX_N 100
int arr[MAX_N+5][MAX_N+5]={0};
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    for()
    return 0;
}