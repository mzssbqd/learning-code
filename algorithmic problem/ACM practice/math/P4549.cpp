#include <iostream>
using namespace std;
int gcd(int a , int b)
{
    return b ? gcd(b , a % b) : a;
}
int main()
{
    int n , a;
    cin >> n;
    cin >> a;
    int temp = abs(a);
    for(int i = 1 ;i < n ;i++)
    {
        cin >> a;
        temp = gcd(temp , abs(a));
    }
    cout << temp <<endl;
    return 0;
}