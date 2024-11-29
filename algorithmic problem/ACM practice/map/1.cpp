#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int M = 1e5 + 10;
const int N = 1e3 + 10;
struct Edge{
    int to, nxt;
}e[2 * M];
int head[N], cnt[N], node_cnt = 0;

int ans[N], num = 0;
int g[N][N];

void add(int a, int b) {
    e[++node_cnt] = {b, head[a]}, head[a] = node_cnt, cnt[a] += 1;
    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        add(a, b), add(b, a);
        g[a][b] = g[b][a] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    for(int i = 1; i <= n; i++) {
        printf("%d", cnt[i]);
        for(int j = head[i]; j != 0; j = e[j].nxt) ans[num++] = e[j].to;
        sort(ans, ans + num);
        for(int j = 0; j < num; j++) printf(" %d", ans[j]);
        printf("\n");
        num = 0;
    }
    return 0;
}