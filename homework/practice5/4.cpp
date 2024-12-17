#include <stdio.h>
#include <cstring>
typedef long long ll;
ll k, m, n;
ll arr[1000];
int main() {
    while(scanf("%lld%lld%lld", &k, &m, &n) != EOF) {
        ll s, t;
        for(int i = 0; i < k; i++) {
            scanf("%lld", &arr[i]);
        }
        for(int i = 0; i <= k - 1; i++) {
            for(int j = 0; j < k - i - 1; j++) {
                if(arr[j] >= arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        s = arr[n - 1], t = arr[k - m];
        printf("%lld %lld\n", t, s);
    }
    return 0;
}