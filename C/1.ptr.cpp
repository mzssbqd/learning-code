#include <stdio.h>
int a[10][10];
int main() {
    a[0][0] = 1;
    printf("%d", **a);
    return 0;
}