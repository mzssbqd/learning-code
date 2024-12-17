#include <stdio.h>
struct num{
    int a, b;
}nums;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b;
    nums.a = 24, nums.b = 64;
    a = nums.a, b = nums.b;
    int d;
    do {
        d = gcd(a, b);
        a /= d, b /= d;
    }while(d != 1);
    printf("%d/%d", a, b);
    return 0;
}