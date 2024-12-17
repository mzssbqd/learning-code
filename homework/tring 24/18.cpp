#include <stdio.h>
const int N = 10005;
typedef long long ll;
ll arr[N], cnt = 0;
int main() {
    ll a, k;
    while(scanf("%lld", &a) != EOF) {
        arr[cnt++] = a;
    }
    k = arr[cnt - 1];
    arr[cnt--] = 0;
    for(int i = cnt - 1; i >= 0; i--) {
        if(k <= arr[i]) {
            arr[i + 1] = arr[i];
            arr[i] = k;
        }
        else {
            arr[i + 1] = k;
            break;
        }
    }
    for(int i = 0; i <= cnt; i++) {
        printf("%lld", arr[i]);
        if(i != cnt) printf(" ");
    }
    return 0;
}