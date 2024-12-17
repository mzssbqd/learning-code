#include <stdio.h>
int arr[150], k = 0;
int main() {
    int n, m, a;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &a);
            int flag = 1;
            for(int t = 0; t < k; t++) {
                if(arr[t] != a) continue;
                flag = 0;
                break;
            }
            if(flag) arr[k++] = a;
        }
    }
    for(int i = 0; i <= k - 1; i++) {
            for(int j = 0; j < k - i - 1; j++) {
                if(arr[j] >= arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
    }
    for(int i = 0; i < k; i++) {
        printf("%d", arr[i]);
        if(i != k - 1) printf(" ");
    }
    return 0;
}