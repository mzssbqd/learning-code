#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 5e6;
ll feet[N + 5],infeet[N + 5];

ll qmi(ll a, int x ,int q)
{
    ll res = 1;
    while(x)
    {
        if(x & 1) res =(ll) res * a % q;
        x >>= 1;
        a =(ll)a * a % q;
    }
    return res;
}
void init()
{
    feet[0] = infeet[0] =1;
    for(int i = 1 ;i <= N ;i++)
    {
        
        feet[i] = (ll)feet[i - 1] * i % mod;
        infeet[i] =(ll)infeet[i - 1] * qmi(i , mod - 2,mod) % mod;
        cout << i <<endl;
    }
    return;
}
int main()
{
    init();
    ll T , n , a , b;
    cin >> T >> n;
    ll res = 0;;
    while(T--)
    {
        scanf("%lld %lld",&a ,&b);
        ll ans = (ll)(feet[a] % mod * infeet[b] % mod * infeet[b - a] % mod);
        res ^=ans;
    }
    printf("%lld",res);
    return 0;
}