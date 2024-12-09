#include <stdio.h>
#include <cstring>
#include <stdlib.h>

int n, x;
int main() {
    
    while(scanf("%d%d", &n, &x) != EOF) {
        int flag = -1;
        for(int i = 1, a; i <= n; i++) {
            scanf("%d", &a);
            if(x == a && flag == -1) flag = i;
        }
       printf("%d\n", flag);
    }
    return 0;
}