#include <iostream>
using namespace std;
const int N = 8e4 + 10;
int stk[N], tt;
int arr[N];
int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        while(tt && arr[stk[tt]] <= arr[i]) {
            ans += i - stk[tt] - 1;
            tt--;
        }
        stk[++tt] = i;
    }
    for(int i = 1; i <= tt;i ++) {
        ans += n - stk[i];
    }
    cout << ans << endl;
    return 0;
}