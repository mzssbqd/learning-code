#include <stdio.h>

int main() {
    double met, N, cnt;
    long long d;
    while(scanf("%lf", &N) != EOF) {
        met = 0, cnt = 1, d = 0;
        while(1) {
            met += 1 / cnt, cnt += 1, d += 1;
            if(met >= N) {
                printf("%lld\n", d);
                break;
            }
        }
    }
    return 0;
}