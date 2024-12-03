#include <stdio.h>

int main() {
  int x, n;
    while(~scanf("%d%d", &x, &n)) {
        
        int size = 10, temp = x;
        while(temp >= 10) {
            temp /= 10;
            size *= 10;
        }
        for(int i = 0; i < n; i++) {
            x += (x % 10) * size;
            x /= 10;
        }
        printf("%d", x);
    }
    return 0;
}