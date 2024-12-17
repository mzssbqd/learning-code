#include <stdio.h>
#include <cstring>
int arr[1000][1000];
int n;
int main() {
    while(scanf("%d", &n) != EOF){
        memset(arr, 0, sizeof arr);
        int p1 = 0;
        int p2 = n / 2;
        for(int i = 1; i <= n * n; i++) {
            arr[p1][p2] = i;
            int new_p1 = (p1 - 1 + n) % n, new_p2 = (p2 + 1) % n;
            if(arr[new_p1][new_p2] != 0) new_p1 = (p1 + 1) % n, new_p2 = p2;
            p1 = new_p1, p2 = new_p2;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d", arr[i][j]);
                if(j != n - 1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}