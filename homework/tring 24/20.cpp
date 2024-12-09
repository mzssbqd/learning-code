#include <stdio.h>
const int N = 1000;
int arr[N][N];
int n, m;

inline int max(int a, int b) {
    return a > b ? a : b;
}
inline int min(int a, int b) {
    return a < b ? a : b;
 }
 int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1;j <= m; j++) {
            scanf("%d", &arr[i][j]);
            arr[i][0] = max(arr[i][0], arr[i][j]);
        }
    }
    int cnt = 0;
    for(int j = 1; j <= m; j++) {
        int ans = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++) {
            ans = min(ans, arr[i][j]);
        }
        for(int k = 1; k <= n; k++) {
            if(arr[k][0] == ans) {
                cnt += 1;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}