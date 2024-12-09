#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) { x = 1, y = 0; return a;}
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve() {
    ll a, b, c, x, y;
    scanf("%lld%lld%lld", &a, &b, &c);
    ll d = exgcd(a, b, x, y);
    if(c % d != 0) { printf("-1\n"); return ; }
    ll x1, y1, n1, n2;
    // x = x1 + kn (k = b / d)
    x1 = x * c / d , y1 = y * c / d ;
    ll kb = b / d, ka = a / d;
    ll d1 = ceil((1 - x1) *1.0 / kb), d2 = floor((y1 - 1) * 1.0 / ka);
    n1 = d1 ,n2 = d2;
    if(d1 <= d2) {
        printf("%lld ", d2 - d1 + 1);
        printf("%lld %lld ", x1 + kb * n1, y1 - ka * n2);
        printf("%lld %lld\n", x1 + kb * n2, y1 - ka * n1);
    }
    else {
        printf("%lld %lld\n", x1 + kb * n1, y1 - ka * n2);
    }
    return ;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}