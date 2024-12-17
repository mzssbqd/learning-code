#include <stdio.h>
#include <cstring>
int main() {
    int st[256];
    char s[10000], t[10000];
    while(scanf("%s%s", s, t) != EOF) {
        memset(st, 0, sizeof st);
        for(int i = 0; s[i]; i++) st[s[i]] += 1;
        for(int i = 0; t[i]; i++) st[t[i]] -= 1;
        int flag = 1;
        for(int i = 0; i < 256; i++) {
            if(st[i] != 0) { printf("No\n"); flag = 0; break; }
        }
        if(flag) printf("Yes\n");
    }
    return 0;
}