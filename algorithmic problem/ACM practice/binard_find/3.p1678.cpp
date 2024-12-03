#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int arr[N];
int n, m;
ll ans;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    while(m--) {
        int s;
        scanf("%d", &s);
        int pos = lower_bound(arr, arr + n, s) - arr;
        if(pos == n) {
            ans += s - arr[pos - 1];
            continue;
        } 
        if(pos != 0) ans += min(arr[pos] - s, abs(s - arr[pos - 1]));
        else ans += arr[pos] - s;
    }
    cout << ans << endl;
    return 0;
}