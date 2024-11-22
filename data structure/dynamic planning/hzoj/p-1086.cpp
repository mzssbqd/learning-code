#include<iostream>
using namespace std;
#define MAX_N 200
#define MAX_K 6
int f[MAX_N+5][MAX_K+6];
int main()
{
    int n,k;
    cin>>n>>k;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int t=1;t<=i;t++)
            {
                f[i][j]+=f[i-t][j-1];
            }
        }
    }
    cout<<f[n][k]<<endl;
    return 0;
}