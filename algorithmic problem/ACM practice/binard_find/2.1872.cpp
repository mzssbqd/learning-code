#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int n, h;
int m;
int arr[N];

bool check(int len) {
    ll cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i] > len) cnt += arr[i] - len;
    }
    if(cnt >= m) return 1;
    return 0;
}
int binary_find() {
	int l, r, mid;
	l = 1, r = h;
	while(l < r) {
        mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return r;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        h = max(h, arr[i]);
    }
    int ans = binary_find();
    cout << ans << endl;
    return 0;
}