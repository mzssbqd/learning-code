#include <iostream>
using namespace std;
typedef long long ll;
ll f[3];
int main()
{
    int mod;
    cin >> mod;
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= 706150 * 706150 ;i++)
    {
        int ind2 = i % 3 ,ind0 = (i - 1) % 3 ,ind1 =(i - 2) % 3;
        f[ind2] = (f[ind0] + f[ind1])%mod;
        if(f[ind2] == 1 && f[ind0] == 0)
        {
            cout << i - 1 <<endl;
            break;
        }
    }
    return 0;
}