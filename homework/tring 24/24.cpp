#include <stdio.h>

int arr[100][100];
int n;
int main() {
    scanf("%d", &n);
    int p1 = 0;
    int p2 = (n) / 2;
    for(int i = 1; i <= n * n; i++) {
        arr[p1][p2] = i;
        int t_p1 = p1, t_p2 = p2;
        if(p1 == 0) p1 = n - 1;
        else p1 -= 1;
        if(p2 == n - 1) p2 = 0;
        else p2 += 1;
        if(arr[p1][p2] != 0) {
            //if(t_p1 + 1 == n - 1) p1 = 0;
            //else p1 = t_p1 + 1;
            p1 = t_p1 + 1;
            p2 = t_p2;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", arr[i][j]);
            if(j != n - 1) printf(" ");
        }
        if(i != n - 1)printf("\n");
    }
    return 0;
}