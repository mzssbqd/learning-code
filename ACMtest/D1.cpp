#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
void solve() {
    ll m, n, a, b, x, y;
    scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
    if(x == y) {
        printf("YES\n");
        return ;
    }
    if(a == 0 && b == 0) {
        printf("NO\n");
        return ;
    }
    if(a == 0) {
        if(((y - x) % b + b) % b == 0 && y < x) printf("YES\n");
        else printf("NO\n");
        return ;
    }
    if(b == 0) {
        if(((y - x) % a + a) % a == 0 && y > x) printf("YES\n");
        else printf("NO\n");
        return ;
    }
    ll d = gcd(a, b);
    if(((y - x) % d + d) % d == 0) { printf("YES\n"); }
    else printf("NO\n");
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