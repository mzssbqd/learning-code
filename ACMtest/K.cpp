#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int a[10][10], b[10][10];
int n, m;

int check(int *arr) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(arr[i][j] == b[i][j]) continue;
            return 0;
        }
    }
    return 1;
}
void dfs(int op, int ind,int* arr, int cnt) {
    if(check(arr)) {
        cout << cnt << endl;
        return ;
    }
    
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            cin >> a[i][j];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            cin >> b[i][j];
    dfs(1, 1);
    return 0;
}