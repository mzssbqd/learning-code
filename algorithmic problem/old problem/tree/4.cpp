#include<iostream>
#include<algorithm>
using namespace std;
#define lowbit(x) ((x)&(-x))
#define MAX_N 100000
int arr[MAX_N+5],c[MAX_N+5];
void add(int i,int x,int n)
{
    if(c[i]==1) return;
    while(i<=n)
    {
        c[i]+=x;
        i+=lowbit(i);
    }
    return;
}
int inqery(int i)
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<sum<<endl;
    return 0;
}