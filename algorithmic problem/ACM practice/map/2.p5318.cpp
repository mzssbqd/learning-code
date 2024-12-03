#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e6 + 10;
vector<int> g[N];
int st[N];
int n, m;

void dfs(int k) {
    st[k] = 1;
    printf("%d ", k);
    for(auto x: g[k]) {
        if(st[x] == 1) continue;
        dfs(x);
    }
    return ;
}

int q[N];
void bfs(int k) {
    memset(st, 0, sizeof st);
    int hh, tt;
    hh = tt = 0;
    q[tt++] = k;
    st[k] = 1;
    while(hh < tt) {
        int cur = q[hh++];
        printf("%d ", cur);
        for(auto x: g[cur]) {
            if(st[x]) continue;
            st[x] = true;
            q[tt++] = x;
        }
    }
    return ;
}
int main() {
    scanf("%d%d", &n, &m);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }
    int beg = N;
    for(int i = 1; i <= N; i++) {
        if(!g[i].empty()) {
            beg = min(beg, i);
            sort(g[i].begin(), g[i].end());
        }
    }
    dfs(beg);
    printf("\n");
    bfs(beg);
    return 0;
}