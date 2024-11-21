#include<iostream>
using namespace std;
#define MAX_N 200
#define MAX_K 20
int f[MAX_N+5][MAX_K+5];
int main()
{
    int n,k;
    cin>>n>>k;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        f[i][1]=1;
        for(int j=1;j<=min(i,k);j++)
        {
            f[i][j]=f[i-1][j-1]+f[i-j][j];
        }
    }
    cout<<f[n][k];
    return 0;
}