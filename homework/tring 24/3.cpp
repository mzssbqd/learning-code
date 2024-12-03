#include <stdio.h>
const int N = 55;
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
        for(int i = 1; i <= n; i++) {
            arr[0][j] = min(arr[0][j], arr[i][j]);
        }
        for(int k = 1; k <= n; k++) {
            if(arr[k][0] == arr[0][j]) {
                
                printf("%d %d %d", k, j, arr[k][j]);
            }
        }
    }
}