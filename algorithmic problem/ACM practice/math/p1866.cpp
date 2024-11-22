#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
#define MAX_N 50

int f[MAX_N + 5];
int arr[MAX_N + 5];
int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ;i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    f[1] = arr[1];
    ll ans = arr[1],flag = 1;
    for(int i = 2;i <= n ;i++)
    {
        f[i] = arr[i] - (arr[i - 1] - f[i - 1] + 1);
        if(f[i] <= 0)
        {
            flag = 0;
            break;
        }
        ans = (ll)ans * f[i] % mod;
    }
    if(flag) cout << ans % mod<< endl;
    else cout << 0 << endl;
    return 0;
}