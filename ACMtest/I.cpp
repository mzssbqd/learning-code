#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

#define sum(i, t) (K[i] * t + B[i])
typedef long long ll;
int n, m;
int K[N], B[N];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%d", &K[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &B[i]);
    ll ans = -0x3f3f3f3f;
    for(int i = 1, t; i <= m; i++) {
        scanf("%d", &t);
        ll ans1 = -0x3f3f3f3f, ans2 = -0x3f3f3f3f;
        for(int j = 1; j <= n; j++) {
            if(sum(j, t) <= ans2) continue;
            if(sum(j, t) >= ans1) ans2 = ans1, ans1 = sum(j, t);
            else ans2 = sum(j, t);
        }
        ans = max(ans, ans1 + ans2);
    }
    printf("%lld", ans);
    return 0;
}