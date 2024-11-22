#include<iostream>
using namespace std;
#define MAX_N 1000000
class Data
{
    public:
    int d;
    int l;
    int r;
};
int n,m;
int a[MAX_N+5];
Data b[MAX_N+5];
int check(int t)
{
    int x[MAX_N+5];
    x[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        x[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=t;i++)
    {
        x[b[i].l]-=b[i].d;
        x[b[i].r+1]+=b[i].d;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=x[i];
        if(sum<0) return 0;
    }
    return 1;
}
int binary()
{
    int l=1,r=m+1,mid;
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
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i].d>>b[i].l>>b[i].r;
    int ind=binary();
    if(ind==m+1) cout<<0<<endl;
    else cout<<-1<<endl<<ind<<endl;  
    return 0;
}