#include <iostream>
using namespace std;
int arr[15];
int n;
int ans = 0;
int a[100001][11];
void output() {
    for(int i = 1; i <= 10; i++) a[ans][i] = arr[i];
    ans += 1;
}
void dfs(int k, int sum) {
    if(sum > n) return ;
    if(k == 11 && sum == n) {
        output();
        return ;
    }
    for(int i = 1; i <= 3; i++) {
        arr[k] = i;
        dfs(k + 1, sum + i);
    }
    return ;
}   
int main() {
    cin >> n;
    if(n > 30) {
        cout << 0 << endl;
        return 0;
    } 
    dfs(1, 0);
    cout << ans << endl;
    for(int i = 0; i < ans; i++) {
        for(int j = 1; j <= 10; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}