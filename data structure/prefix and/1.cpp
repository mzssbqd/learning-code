#include<iostream>
using namespace std;
#define MAX_N 1000000
class Data
{
    public:
    long long d;
    long long l;
    long long r;
};
long long n,m;
long long a[MAX_N+5];
Data b[MAX_N+5];
long long check(long long t)
{
    long long x[MAX_N+5];
    x[1]=a[1];
    for(long long i=2;i<=n;i++)
    {
        x[i]=a[i]-a[i-1];
    }
    for(long long i=1;i<=t;i++)
    {
        x[b[i].l]-=b[i].d;
        x[b[i].r+1]+=b[i].d;
    }
    long long sum=0;
    for(long long i=1;i<=n;i++)
    {
        sum+=x[i];
        if(sum<0) return 0;
    }
    return 1;
}
long long binary()
{
    long long l=1,r=m+1,mid;
    while( l< r)
    {
        mid=(l+r)/2;
        if(check(mid)==1) l=mid+1;
        else r=mid;
        mid=(l+r)/2;//1 0 
    }
    return l;
}
int main()
{   
    
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    for(long long i=1;i<=m;i++) cin>>b[i].d>>b[i].l>>b[i].r;
    long long ind=binary();
    if(ind==m+1) cout<<0<<endl;
    else cout<<-1<<endl<<ind<<endl;  
    return 0;
}