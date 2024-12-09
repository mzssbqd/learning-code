#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e18 + 5;
ll arr[45];
ll n ,m;
vector<ll> da, db;
void dfs(ll l,ll r, ll sum, vector<ll> &v) {
    if(sum > m) return ;
    if(l > r) {
        v.push_back(sum);
        return ;
    }
    dfs(l + 1, r, sum + arr[l], v);
    dfs(l + 1, r, sum, v);
    return ;
}
int main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    int mid = n >> 1;
    dfs(1, mid, 0, da);
    dfs(mid + 1, n, 0, db);
    sort(da.begin(), da.end());
    ll ans = 0;
    for(int i = 0, I = db.size(); i < I; i++) {
        ans += upper_bound(da.begin(), da.end(), m - db[i]) - da.begin();
    }   
    printf("%lld", ans);
    return 0;
}