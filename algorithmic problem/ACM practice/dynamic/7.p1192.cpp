#include <iostream>
using namespace std;
#define MAX_N 100000
int f[MAX_N + 5];
const int mod = 100003;
int main()
{
    int n , k;
    cin >> n >> k;
    f[1] = 1;
    f[0] = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= k ; j++)
        {
            if(i - j >= 0) f[i] = (f[i] + f[i - j]) % mod;
        }
    }
    cout << f[n] % mod <<endl;
    return 0;
}