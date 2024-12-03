#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll a[N], D[N];
int main() {
    int n;
    ll k = 0, t = 0;
    ll ans1 = 0, ans2 = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        D[i] = a[i] - a[i - 1];
        if(i == 1) continue;
        if(D[i] > 0) k += D[i];
        else t -= D[i];
    }
    ans1 = max(k, t), ans2 = abs(k - t) + 1;
    cout << ans1 << endl << ans2 << endl;
    return 0;
}