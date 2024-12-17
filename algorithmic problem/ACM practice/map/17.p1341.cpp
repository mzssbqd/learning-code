#include<bits/stdc++.h>
using namespace std;
const int N = 260;
int g[N][N], degree[N];
char ans[N];
int cnt;
int n;
void dfs(int ind) {
    for(int i = 0; i <= 256; i++) {
        if(g[ind][i]) {
            g[ind][i] = 0, g[i][ind] = 0;
            dfs(i);
        }
    }
    ans[cnt++] = (char)ind;
    return ;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        g[a][b] = 1, g[b][a] = 1;
        degree[a] += 1, degree[b] += 1;
    }
    int ind = 0x3f3f3f3f, cnt = 0;
    for(int i = 0; i <= 257; i++) {
        if(degree[i] & 1) {
            cnt += 1;
            ind = min(ind, i);
            continue;
        }
        if(degree[i] != 0) ind = min(ind, i);
    } 
    if(!cnt || cnt == 2) dfs(ind);
    else {
        cout << "No Solution" << endl;
        return 0;
    }
    if(cnt == n + 1)
        for(int i = cnt - 1; i >= 1; i--) cout << ans[i];
    else cout << "No Solution" << endl;
    return 0;
}