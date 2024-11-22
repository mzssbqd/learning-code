#include<iostream>
using namespace std;
#define MAX_N 500000
long long arr[MAX_N+5]={0};
long long temp[MAX_N+5]={0};
long long merge(long long arr[],long long l,long long r)
{
    if(r-l<=1) return 0;
    long long mid=(l+r)/2;//3 mid =2  0  1   0 1  
    long long a=0,b=0,c=0;
    a=merge(arr,l,mid);
    b=merge(arr,mid,r);
    long long p1=l,p2=mid,p0=0;
    while( p1<mid || p2<r)
    {
        if(p1<mid && ( p2>=r || arr[p1]<=arr[p2])) temp[p0++]=arr[p1++];
        else 
        {
            c+=(mid-p1);
            temp[p0++]=arr[p2++];
        }
    }
    for(long long i=l;i<r;i++) arr[i]=temp[i-l];
    return a+b+c;
}
int main(){
    long long x;
    while(1)
    {
        scanf("%lld",&x);
        if(x==0) break;
        for(int i=0;i<x;i++)
        {
            scanf("%lld",&arr[i]);
        }
        printf("%lld\n",merge(arr,0,x));
    }
    return 0;
}