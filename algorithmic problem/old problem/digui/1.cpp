#include<iostream>
using namespace std;
#define MAX_N 1000
int f[MAX_N+5];
int main()
{
    int n;
    cin>>n;
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=i/2;j++)
        {
            f[i]+=f[j];
        }
    }
    cout<<f[n]<<endl;
    return 0;
}