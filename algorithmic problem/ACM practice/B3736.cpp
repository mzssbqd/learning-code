#include<iostream>
using namespace std;


int gcd(int a,int b)
{
    return a = ( b == 0 ? a : gcd(b , a % b));
}
int main()
{
    int a,b,c;
    cin>>a >> b >>c;
    cout<<gcd(gcd(a,b),c);

    return 0;
}