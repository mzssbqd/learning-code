#include <stdio.h>

int main(){
    int n, t;
    scanf("%d %d", &n, &t);
    long long a = 1;
    for(int i = 1; i < n; i++){
        a = (a + t) * 2;
    }
    printf("%lld", a);
    return 0;
}