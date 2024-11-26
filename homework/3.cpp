#include <stdio.h>
char s[10000];
int string_length(const char *s) {
    int ans = 0;
    for(int i = 0; s[i]; i++) ans += 1;
    return ans;
}
int main() {
    scanf("%s" ,s);
    printf("%d", string_length(s));
    return 0;
}