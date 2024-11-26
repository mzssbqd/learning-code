    #include <stdio.h>

    unsigned long long factorial(int n) {
        unsigned long long temp = 1;
        for(int i = 1; i <= n; i++) {
            temp *= i;
        }
        return temp;
    }
    int main() {
        int n;
        scanf("%d", &n);
        printf("%lld", factorial(n));
        return 0;
    }