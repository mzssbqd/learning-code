#include <stdio.h>
const int N = 1010;
char a[N], b[N];
int main() {
    while(scanf("%s%s", a, b) != EOF) {
        int st[256] = {0};
        for(int i = 0; b[i]; i++) st[(int)b[i]] = 1;
        for(int i = 0; a[i]; i++) {
            if(st[(int)a[i]] != 0) continue;
            printf("%c", a[i]);
        }
        printf("\n");
    }
    return 0;
}