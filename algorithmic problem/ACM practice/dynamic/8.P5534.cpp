#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int a1 , a2 ,n;
    cin >> a1 >> a2 >> n;
    ll d = a2 - a1;
    cout <<n * (2 * a1 + (n - 1) * d) / 2 <<endl;
    return 0;   
}