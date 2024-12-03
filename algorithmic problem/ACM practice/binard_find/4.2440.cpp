#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, k, h;
int arr[N];
bool check(int len) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += (arr[i] - (arr[i] % len)) / len;
    if(cnt >= k) return 1;
    return 0;
}
int binary_find() {
	int l, r, mid;
	l = 0, r = h;
	while(l < r) {
        mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return r;
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        h = max(h, arr[i]);
    }
    int ans = binary_find();
    cout << ans << endl;
    return 0;
}