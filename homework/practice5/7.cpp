#include <stdio.h>

int main() {
    long long t;
    while(scanf("%lld", &t) != EOF) {
        while(t > 10) {
            long long temp = t, ans = 0;
            while(temp) {
                ans += temp % 10;
                temp /= 10;
            }
            t = ans;
        }
        printf("%lld\n", t);
    }
    return 0;
}