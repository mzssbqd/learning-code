#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    a=a*37;
    int size=a%10;
    while(a>0)
    {
        if(size!=a%10) 
        {
            cout<<"No"<<endl;
            return 0;
        }
        a/=10;
    }
    cout<<"Yes"<<endl;
    return 0;
}