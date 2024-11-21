#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<time.h>
#define FATHER(i) (i/2)
#define LEFT(i) (i*2)
#define RIGHT(i) (i*2+1)
using namespace std;
void test(auto* func,int* arr,int n)
{
    printf("TEST: %s\n",__func__);
    int *temp=new int[n];
    memcpy(temp,arr,sizeof(int)*n);
    long long b=clock();
    func(temp,n);
    long long e=clock();
    cout<<"time:"<<1000*(e-b)/CLOCKS_PER_SEC<<endl;
    free(temp);
}
int *getRandomData(int n)
{
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand() % 1000;
    }
    return arr;
}
inline void up_updata(int *data,int i)
{
    while(i > 1 && data[i] > data[FATHER(i)]){
        swap(data[i],data[FATHER(i)]);
        i=FATHER(i);
    }
    return;
}

inline void down_updata(int* data,int i,int n)
{
    while(LEFT(i)<=n)
    {
        int ind=i,l=LEFT(i),r=RIGHT(i);
        if(data[l] > data[ind]) ind=l;
        if(data[r] > data[ind]) ind=r;
        if(ind == i) return;
        swap(data[ind] , data[i]);
        i=ind;
    }
}
void linear_heap(int *arr,int n)
{
    int* data=arr-1;
    for(int i=n/2;i>=1;i--)
    {
        down_updata(data,i,n);
    }
    for(int i=n;i>=2;i--)
    {
        swap(data[1],data[i]);
        down_updata(data,1,i-1);
    }
    return;
}
void normal_heap(int *arr,int n)
{
    int *data=arr-1;
    for(int i=2;i<=n;i++)
    {
        up_updata(data,i);
    }
    for(int i=n;i>=2;i--)
    {
        swap(data[1],data[i]);
        down_updata(data,1,i-1);
    }
    return;
}
int main()
{
    srand(time(NULL));
    #define MAX_N 100000
    int *arr=getRandomData(MAX_N);
    test(linear_heap,arr,MAX_N);
    test(normal_heap,arr,MAX_N);
    return 0;
}