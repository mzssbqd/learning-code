#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e4 + 10, M = 2e4 + 10;

struct Edge{
    int to, nxt, w;
}e[2 * M];
int head[N], st[N], dist[N], cnt = 0;
int n, m, s, k;
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c}, head[a] = cnt;
    return ;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    while(!q.empty()) {
        auto temp = q.top();
        q.pop();
        int t = temp.second, t_dis = temp.first;
        if(st[t]) continue;
        st[t] = 1;
        for(int i = head[t]; i != 0; i = e[i].nxt) {
            int j = e[i].to;
            int mdis = max(t_dis, e[i].w);
            if(dist[j] > mdis) {
                dist[j] = mdis;
                q.push({dist[j], j});
            }
        }
    }
    return dist[k];
}
int main() {
    cin >> n >> m >> s >> k;
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    int ans = dijkstra();
    cout << ans << endl;
    return 0;
}
