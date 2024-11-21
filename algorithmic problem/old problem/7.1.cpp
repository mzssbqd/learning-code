#include<iostream>
#include <climits>
using namespace std;
int main()
{
    
    long long a,b;
    long long c=1;
    cin>>a>>b;
    for(int i=1;i<=b;i++)
    {
        c*=a;
        if(c>INT_MAX)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<c<<endl;
    return 0;
}