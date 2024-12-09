#include <stdio.h>
#include <cstring>
int st1[256], st2[256];
int main() {
    char s1[10001], s2[10001];
    
    while(scanf("%s %s", s1, s2) != EOF) {
        int flag = 1;
        memset(st1, 0, sizeof st1);
        memset(st2, 0, sizeof st2);
        for(int i = 0; s1[i]; i++) st1[s1[i]] = 1;
        for(int i = 0; s2[i]; i++) st2[s2[i]] = 1;
        for(int i = 0; i < 256; i++) {
            if(st1[i] != st2[i]) {
                flag = 0;
                break;
            }
        }
        printf("%s ", flag ? "Yes" : "No");
    }
    return 0;
}