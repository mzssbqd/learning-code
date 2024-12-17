#include <stdio.h>

int arr[15], st[15];
int n;
void dfs(int step) {
    if(step == n + 1) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(st[i] == 1) continue;
        arr[step] = i, st[i] = 1;
        dfs(step + 1);
        st[i] = 0;
    }
}
int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}