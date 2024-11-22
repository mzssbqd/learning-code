#include<iostream>
using namespace std;
#define MAX_N 18
int f[MAX_N+5];
int main()
{
    int n;
    cin>>n;//f(n)=n*f(n-1)
    f[1]=1;
    for(int i=2;i<=n;i++) f[n]=n*f[n-1];
    cout<<f[n]<<endl;
    return 0;
}