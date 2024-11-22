#include<iostream>
using namespace std;
int main()
{
    double sum=0,k;
    cin>>k;
    double i=1.0;
    for(;sum<=k;i++)
    {
        sum+=1.0/i;
    }
    cout<<--i<<endl;
    return 0;
}