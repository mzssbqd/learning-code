#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) { x = 1, y = 0; return a;}
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
void solve() {
    ll m, n, a, b, x, y;
    scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
    ll c = y - x;
    if(x == y) {
        printf("YES\n");
        return ;
    }
    if(a == 0 && b == 0) {
        printf("YES\n");
        return ;
    }
    if(a == 0) {
        if((c % b + b) % b == 0 && y < x) printf("YES\n");
        else printf("NO\n");
        return ;
    }
    if(b == 0) {
        if((c % a + a) % a == 0 && y > x) printf("YES\n");
        else printf("NO\n");
        return ;
    }
    int d = exgcd(a, b, m, n);
    if(abs(y - x) % d != 0) { printf("NO\n"); return ; }
    else printf("YES\n");
    return ;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}