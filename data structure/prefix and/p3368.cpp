#include<iostream>
using namespace std;
#define MAX_N 500000
int arr[MAX_N+5],c[MAX_N+5];
#define lowbit(x) ((x)&(-x))
int add(int i,int k,int n)
{
    while(i<=n)
    {
        c[i]+=k;
        i+=lowbit(i);
    }
    return 0;
}
int prefix(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}
int main()
{
    int n,m;
    cin>>n>>m;
    arr[0]=c[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        add(i,arr[i]-arr[i-1],n);
    }
    for(int i=0,x,y,k,scode;i<m;i++)
    {
        cin>>scode;
        switch(scode)
        {
            case 1:
            {
                cin>>x>>y>>k;
                add(x,k,n);
                add(y+1,-k,n);
            }break;
            case 2:
            {
                cin>>x;
                cout<<prefix(x)<<endl;
            }break;
        }
    }
    return 0;
}