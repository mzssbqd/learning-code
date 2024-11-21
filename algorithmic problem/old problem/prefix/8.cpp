#include<iostream>
using namespace std;
#define lowbit(x) ((x)&(-x))
#define MAX_N 5000000
long long arr[MAX_N+5]={0},c[MAX_N+5]={0};
void add(long long i,long long x,long long n)
{
    while(i<=n)
    {
        c[i]+=x;
        i+=lowbit(i);
    }
    return;
}
long long inqery(long long i)
{
    long long sum=0;
    while(i>0)
    {
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}
int main()
{
    long long n,p;
    cin>>n>>p;
    arr[0]=0,c[0]=0;
    for(long long i=1;i<=n;i++) 
    {
        cin>>arr[i];
        add(i,arr[i]-arr[i-1],n);
    }
    for(long long i=0,x,y,z;i<p;i++)
    {
        cin>>x>>y>>z;
        add(x,z,n);
        add(y+1,-z,n);
    }
    long long mus=inqery(1);
    for(long long j=1;j<=n;j++)
    {
        mus=min(mus,inqery(j));
    }
    cout<<mus<<endl;
    return 0;
}