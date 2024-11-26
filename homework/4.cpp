#include <stdio.h>

int is_prime(int n) {
    for(int i = 2; i <= n / i; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", is_prime(n));
    return 0;
}