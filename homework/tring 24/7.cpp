#include <stdio.h>
#include <cstring> 
int b[1010], cnt = 0;
void slove() {
    cnt = 0;
    int n, x;
    scanf("%d%d", &n, &x);
    for(int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        if(x > a) b[cnt++] = a;
    }
    for(int i = 0; i < cnt; i++) {
        int ans = i + 1;
        for(int j = i; j < cnt; j++) {
            if(b[ans] > b[j]) ans = j;
        }
        int temp = b[i];
        b[i] = b[ans];
        b[ans] = temp;
        printf("%d ", b[i]);
    }
    return ;
}
int main() {
    while(scanf("") != EOF) {
        slove();
    }
    return 0;
}