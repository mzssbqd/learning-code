#include<iostream>
using namespace std;
#define MAX_N 100
int f[105]={0};
//逆向递推(循环实现)
int main()
{
    int n;
    cin>>n;
    f[1]=1,f[2]=2;
    for(int i=3;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    cout<<f[n]<<endl;
    return 0;
}