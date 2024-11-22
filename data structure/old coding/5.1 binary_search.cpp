#include<iostream>
#include<cstdio>
#include<time.h>
using namespace std;
void output(int arr[],int ind=-1)
{
    int len=0;
    for(int i=0;i<10;i++) len+=printf("%4d",i);
    printf("\n");
    for(int i=0;i<len;i++) printf("-");
    printf("\n");
    for(int i=0;i<10;i++) 
    {
        if(ind==i) printf("\033[1;32m");
        printf("%4d",arr[i]);
        if(ind==i) printf("\033[0m");
    }
    printf("\n");
    return;
}
int binary_search(int *arr,int n,int x)
{
    int head=0,tail=n-1;
    while(head<=tail)
    {
        int mid=(head+tail)/2;
        if(x==arr[mid]) return mid;
        if(x<arr[mid]) tail=mid-1;
        else head=mid+1; 
    }
    return -1;
}
void test01(int n)
{
    srand(time(NULL));
    int *arr=new int[n];
    arr[0]=rand()%10;
    for(int i=1;i<10;i++) arr[i]=arr[i-1]+rand()%10;
    output(arr);
    int x;
    while(~scanf("%d",&x))
    {
        if(x==-1) break;
        int ind=binary_search(arr,n,x);
        output(arr,ind);
    }
}
double f(double x)
{
    double tax=0;
    if( x>=0 ) tax+=min(x,(double)3000)*0.03;
    if( x>=3000 ) tax+=(min(x,(double)12000)-3000)*0.1;
    if( x>=12000 ) tax+=(min(x,(double)25000)-12000)*0.2;
    if( x>=25000 ) tax+=(min(x,(double)32000)-25000)*0.25;
    if( x>=32000 ) tax+=(min(x,(double)55000)-32000)*0.30;
    if( x>=55000 ) tax+=(min(x,(double)80000)-55000)*0.40;
    if( x>=80000 ) tax+=(x-80000)*0.45;
    x-=tax;
    return x;
}
#define EXP 1e-2
double binary_algorithm(double y)
{
    double head=0,tail=100000;
    while(tail-head>=EXP)
    {
        double mid=(head+tail)/2.0000;
        cout<<mid<<endl;
        if(abs(y-f(mid))<=EXP) return mid;
        if(y < f(mid)) tail=mid;
        else head=mid;
    }
    return head;
}
void test02()
{
    double y;
    while(~scanf("%lf",&y))
    {
        if(y<0) break;
        double x=binary_algorithm(y);
        printf("f(%lf):%lf\n",x,y);
    }
    return;
}
int main()
{
    #define MAX_N 10
    //test01(MAX_N);
    test02();
}