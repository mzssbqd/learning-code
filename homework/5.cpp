#include <stdio.h>
#include <string.h>

void reverse_string(const char *s) {
    int slen = strlen(s);
    for(int i = slen - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    return ;
}
int main() {
    char s[10000];
    scanf("%s", &s);
    reverse_string(s);
    return 0;
}