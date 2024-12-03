#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[25][25];

int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) a[0][i] = 1; 
    for(int i = 1; i < n; i++) {
        a[i][0] = 1;
        for(int j = 1; j < n; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}