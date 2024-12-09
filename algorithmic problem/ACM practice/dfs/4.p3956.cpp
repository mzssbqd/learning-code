#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 历史答案剪枝
int g[105][105], m, n;
int cat[105][105];
int vis[105][105];
int dir[4][2] = {
    {1, 0} , {0, 1},
    {-1, 0}, {0, -1}
};
ll ans = 0x3f3f3f3f;
void dfs(int i, int j, int x, int y, ll sum, int color, int flag) {
    printf("%d %d %lld\n", i, j, sum);
    if(i == x && j == y) {
        ans = min(ans, sum);
        return ;
    }
    for(int k = 0; k < 4; k++) {
        int dx = i + dir[k][0], dy = j + dir[k][1];
        if(vis[dx][dy] == 0) continue;
        vis[dx][dy] = 0;
        if(g[dx][dy] == g[i][j]) {
            dfs(dx, dy, x, y, sum, color, 1);
        }
        else if(g[dx][dy] == -1 && flag == 1) {
            if(sum + 2>= ans) continue;
            dfs(dx, dy, x, y, sum + 2, color, 0);
        }else {
            if(sum + 1>= ans) continue;
            dfs(dx, dy, x, y, sum + 1, 1 - color, 1);
        }
        vis[dx][dy] = 1;
    }
}
int main() {
    cin >> m >> n;
    memset(g, -1, sizeof g);
    for(int i = 0, x, y, c; i < n; i++) {
        scanf("%d%d%d", &x, &y, &c);
        g[x][y] = c;
    }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            vis[i][j] = 1;
    dfs(1, 1, m, m, 0, g[1][1], 1);
    printf("%lld", ans);
    return 0;
}