#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int m_len = 2 * n - 1;
        int z1, z2;
        z1 = z2 = (m_len  + 1)/ 2;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= m_len; j++) {
                if(j == z1 || j == z2) printf("*");
                else printf(" ");
            }
            printf("\n");
            z1 -= 1, z2 += 1;
        }
        for(int i = 0, f = 1; i <= m_len; i++) {
            if(f) printf("*");
            else printf(" ");
            f = 1 - f;
        }
        printf("\n");
    }
    return 0;
}