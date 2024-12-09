    #include <stdio.h>

    int main() {
        long long x, n;
        while(scanf("%lld%lld", &x, &n) != EOF) {
            long long size = 10, temp = x;
            while(temp >= 10) {
                temp /= 10;
                size *= 10;
            }
            size /= 10;
            for(int i = 0, m; i < n; i++) {
                m = x / size;
                x -= size * m;
                x = x * 10 + m;
            }
            printf("%lld\n", x);
        }
        return 0;
    }