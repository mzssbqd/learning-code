#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll K[N], B[N];
vector<ll> s;
int n, m;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> K[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    ll ans = -0x3f3f3f3f;
    for(int i = 0, a; i < m; i++) {
        cin >> a;
        if(i == 0) {
            for(int j = 0; j < n; j++) {
                s.push_back(K[j] * a + B[j]);
            }
            sort(s.begin(), s.end(), greater<ll>());
            ans = max(ans, *s.begin() + *(s.begin() + 1));
            s.clear();
        }
        if(i == m - 1) {
            for(int j = 0; j < n; j++) {
                s.push_back(K[j] * a + B[j]);
            }
            sort(s.begin(), s.end(), greater<ll>());
            ans = max(ans, *s.begin() + *(s.begin() + 1));
        }
    }
    cout << ans << endl;
    return 0;
}