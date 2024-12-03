#include <iostream>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
ll n, y, x, mx;
ll a[N], b[N];


bool check(ll t) {
    ll cnt = 0;
    for(int i = 1; i <= n; i++) {
        ll temp = max((ll)0, b[i] - t);
        if(a[i] >= temp) continue;
        cnt += (temp - a[i] + y - 1) / y;
    }
    if(cnt <= x) return 1;
    return 0;
}
ll binary_find() {
	ll l, r, mid;
	l = 0, r = mx;
	while(l < r) {
        mid = (l + r) >> 1;
        if(check(mid)) r = mid;
		else l = mid + 1;
	}
	return r;
}
int main() {
    cin >> n >> y >> x;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        mx = max(mx, b[i]);
    }
    ll ans = binary_find();
    printf("%lld", ans);
    return 0;
}