#include<iostream>
using namespace std;
int main()
{
    int a,b,k;
    cin>>a>>b>>k;
    int cnt=0;
    while(a<b)
    {
        a=a*k;
        cnt+=1;
        if(a*k>b) break;
    }
    while(a!=b)
    {
        a+=1,cnt+=1;
    }
    cout<<cnt<<endl;
    return 0;
}