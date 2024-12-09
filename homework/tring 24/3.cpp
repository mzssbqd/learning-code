#include <stdio.h>
const int N = 200;
int arr[N][N];
int n, m;

int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
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
    for(int j = 1; j <= m; j++) {
        int ans = 5000;
        for(int i = 1; i <= n; i++) {
            ans = min(ans, arr[i][j]);
        }
        for(int k = 1; k <= n; k++) {
            if(arr[k][0] == ans) {
                printf("%d %d %d", k - 1, j - 1, arr[k][j]);
                return 0;
            }
        }
    }
    printf("It does not exist!");
    return 0;
}