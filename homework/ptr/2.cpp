#include <stdio.h>
#include <cstring>
char s[100000];
int main() {
    scanf("%s", s);
    char *p = &s[0];
    int cnt = 0;
    for(int i = 0; s[i]; i++) p++, cnt += 1;
    p--;
    for(int i = cnt - 1; i >= 0; i--) {
        printf("%c", *p);
        p--;
    }
    return 0;
}