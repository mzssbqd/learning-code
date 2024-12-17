#include <stdio.h>
#include <cstring>
typedef long long ll;
ll arr[100], cnt = 0;

void process_digit() {
    for(int i = 0; i <= cnt; i++) {
        if(arr[i] < 10) continue;
        if(i == cnt) cnt += 1;
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
    }
    return ;
}
int main() {
    ll a, b;
    while(scanf("%lld%lld", &a, &b) != EOF) {
        memset(arr, 0, sizeof arr);
        cnt = 0;
        arr[0] += a;
        process_digit();
        arr[0] += b;
        process_digit();
        for(int i = 0; i <= cnt; i++) printf("%lld", arr[i]);
        printf("    \n");
    }
    return 0;
}