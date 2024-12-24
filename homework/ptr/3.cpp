#include <stdio.h>
#include <stdlib.h>
int *allocate_and_fill(int n) {
    int *p = (int *)malloc(sizeof(int) * n);
    return p;
}
int main() {
    long long n, sum;
    scanf("%lld", &n);
    int *a = allocate_and_fill(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%.2lf", sum * 1.0 / n);
    free(a);
    return 0;
}