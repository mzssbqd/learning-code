#include<iostream>
using namespace std;
#define MAX_N 500000
long long arr[MAX_N+5],temp[MAX_N+5];
long long merge_sort(int l,int r)
{
    if(r-l<=1) return 0;
    long long sum=0;
    long long mid=(l+r)/2;
    sum+=merge_sort(l,mid);
    sum+=merge_sort(mid,r);
    int p1=l,p2=mid,p0=0;
    while(p1<mid || p2<r)
    {
        if(p1<mid && (p2>=r || arr[p1]<=arr[p2])) 
        {

            temp[p0++]=arr[p1++];
        }
        else 
        {
            if(p2<r) 
            {
                sum+=mid-p1;
            }
            temp[p0++]=arr[p2++];
        }
    }
    for(int i=l;i<r;i++)
    {
        arr[i]=temp[i-l];
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
    long long sum;
    sum=merge_sort(0,n);
    cout<<sum<<endl;
    return 0;
}