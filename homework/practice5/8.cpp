#include <stdio.h>
typedef long long ll;

ll gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll d = gcd(a, b);
    ll k = a / d * b;
    printf("%lld %lld", d, k);
    return 0;
}