#include<iostream>
using namespace std;
#define MAX_N 10000
int arr[MAX_N+5][MAX_N+5]={0};
int main()
{
    int n,r,max_x=0,max_y=0;
    cin>>n>>r;
    max_x=r,max_y=r;
    for(int j=1,x,y,w;j<=n;j++)
    {
        cin>>x>>y>>w;
        arr[x+1][y+1]+=w;
        if(max_x<x+1) max_x=x+1;
        if(max_y<y+1) max_y=y+1;
    }
    for(int i=1;i<=max_x;i++)
    {
        for(int j=1;j<=max_y;j++)
        {
            arr[i][j]+=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
        }
    }
    int sum=0;
    for(int i=1;i<=max_x-r+1;i++)
    {
        for(int j=1;j<=max_y-r+1;j++)
        {
            int x=i+r-1,y=j+r-1;
            sum=max(sum,arr[x][y]-arr[x][j-1]-arr[i-1][y]+arr[i-1][j-1]);
        }
    }
    cout<<sum<<endl;
    return 0;
}