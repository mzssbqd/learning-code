#include <stdio.h>
const int N = 1010;
char a[N], b[N];
void slove() {
    int st[256] = {0};
    scanf("%s", a);
    scanf("%s", b);
    for(int i = 0; b[i]; i++) st[b[i]] += 1;
    for(int i = 0; a[i]; i++) {
        if(st[a[i]] != 0) continue;
        printf("%c", a[i]);
    }
    printf(" ");
    return ;
}
int main() {
    while(scanf("") != EOF) {
        slove();
    }
    return 0;
}