#include <stdio.h>
#include <cstring>
char s[100000000];
int main()
{
    int x = 3;
    char c;
    while(x--) {
        fgets(s, sizeof s, stdin);
        int n = 0, m = 0, k = 0, t = 0, u = 0;
        for(int i = 0; i < 80; i++) {
            c = s[i];
            if(c >= 'A' && c <= 'Z'){
                n += 1;
                continue;
            }
            if(c >= 'a' && c <= 'z') {
                u += 1;
                continue;
            }
            if(c >= '0' && c <= '9'){
                k += 1;
                continue;
            }
            if(c == ' '){
                m += 1;
                continue;
            }
            t += 1;
        }
        printf("%d %d %d %d %d\n", n, u, k, m, t);
    }
        
    return 0;
}