#include<iostream>
using namespace std;
#define lowbit(x) ((x)&(-x))
int main()
{
    int x;
    cin>>x;
    while(x>0)
    {
        cout<<lowbit(x);
        x-=lowbit(x);
        if(x>0) cout<<"+";
    }
    return 0;
}