#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((a+b)*c==d) 
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if((a+b)+c==d) 
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if((a+b)-c==d) 
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if((a-b)+c==d) 
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if((a-b)-c==d) 
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if((a-b)*c==d) 
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if((a*b)*c==d) 
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if((a*b)-c==d) 
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if((a*b)+c==d) 
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}