#include<iostream>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(cin>>n && t>0)
    {
        int n0=0,n1=0;
        if(n<0){
            n1+=1;
            n-=1;
            n=~n;
        }
        while(n>0)
        {
            if(n&1) n1+=1;
            n>>=1;
        }
        if(n1>16) cout<<n0<<endl;
        else cout<<n1<<endl;
        t-=1;
    }
    return 0;
}