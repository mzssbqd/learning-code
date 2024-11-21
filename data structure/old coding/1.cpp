#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<vector>
using namespace std;
void junction(int* arr,const int& x,const int& a,const int& b)
{
    for(int i=a;i<=b;i++)
    {
        cout<<"1 ";
        arr[i]=(arr[i]+x)%4;
        cout<<(arr[i])<<" ";
    }
    return;
}
int main()
{
    int L,M;
    scanf("%d %d",&L,&M);
    int *arr=(int*)malloc(sizeof(int)*(L+1));
    memset(arr,0,sizeof(arr));
    int operate[4]={1,3,2};
    int x,a,b,n=0;
    while(n<M && ~scanf("%d %d %d",&x,&a,&b))
    {
        n++;
        junction(arr,operate[x],a,b);
    }
    int num=0;
    for(int i=1;i<=L;i++)
    {
        if(arr[i]==1) num++;
    }
    cout<<num<<endl;
    return 0;
}