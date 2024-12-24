#include <stdio.h>
#include <cstring>
typedef long long ll;
ll arr[100], cnt = 0, flag = 0;

int max(int a, int b) {
    return a > b ? a : b;
}
void process_digit() {
    for(int i = 0; i <= cnt; i++) {
        if(arr[i] < 10) continue;
        if(i == cnt) cnt += 1;
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
    }
    for(int i = cnt; i >= 0; i--) {
        if(arr[i] == 0) cnt -= 1;
        else break;
    }
    return ;
}
int main() {
    char a[50], b[50]; // 1234 4 3 2 1
    while(scanf("%s%s", a, b) != EOF) {
        cnt = 0;
        memset(arr, 0, sizeof arr);
        for(int i = 0, I = strlen(a); a[i]; i++) {
            arr[I - i - 1] += a[i] - '0';
        }
        cnt = max(cnt, strlen(a));
        process_digit();
        for(int i = 0, I = strlen(b); b[i]; i++) {
            arr[I - i - 1] += b[i] - '0';
        }
        cnt = max(cnt, strlen(b));
        process_digit();
        for(int i = cnt; i >= 0; i--) {
           printf("%lld", arr[i]);
        }
        printf("\n");
    }
    return 0;
}