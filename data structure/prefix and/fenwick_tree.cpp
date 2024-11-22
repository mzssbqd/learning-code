#include<iostream>
using namespace std;
#define lowbit(x) ((x)&(-x))
int a[10000];
int c[10000];
int query(int i)
{
    int sum=0;
    while(i)
    {
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}
int add(int i,int x,int n)
{
    while(i<=n)
    {
        c[i]+=x;
        i+=lowbit(i);
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        add(i,a[i],n);
    }
    return 0;
}