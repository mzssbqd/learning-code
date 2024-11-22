#include<iostream>
#include<vector>
using namespace std;
#define lowbit(x) ((x)&(-x))
long long n,m;
long long arr[1000005],c[1000005];
int add(long long x,long long k)
{
    while(x<=n)
    {
        c[x]+=k;
        x+=lowbit(x);
    }
    return 0;
}
long long inqery(int x)
{
    long long sum=0;
    while(x>0)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        add(i,arr[i]);
    }
    for(int i=1,x,k,scode;i<=m;i++)
    {
        cin>>scode;
        switch(scode)
        {
            case 1:
            {
                cin>>x>>k;
                add(x,k);
            }break;
            case 2:
            {
                cin>>x>>k;
                cout<<(inqery(k)-inqery(x-1))<<endl;
            }break;
        }
    }
    return 0;
}