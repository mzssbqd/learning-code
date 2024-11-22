#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long n,Q,scode=0;
    scanf("%lld",&n);
    vector<long long> arr(n);
    for(long long& x:arr) scanf("%lld",&x);
    //sort
    vector<int> down(n);
    for(int i=0;i<n;i++) down[i]=i;
    sort(down.begin(),down.end(),[&](int i,int j)->bool
    {
        return arr[i]<arr[j];
    });
    scanf("%lld",&Q);
    vector<long long> num(Q);
    for(long long& x:num) scanf("%lld",&x);
    for(long long i=0;i<Q;i++)
    {
        long long begin=0,end=n-1,mid=n/2;
        while(begin<=end)
        {
            if(num[i]==arr[down[mid]]) 
            {
                num[i]=down[mid]+1;
                scode=1;
                break;
            }
            if(num[i]>arr[down[mid]]) begin=mid+1;
            if(num[i]<arr[down[mid]]) end=mid-1;
            mid=(begin+end+1)/2;
        }
        if(scode==0) num[i]=0;
        scode=0;
    }
    for(long long& x:num) cout<<x<<endl;
    return 0;
}