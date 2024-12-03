#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5, M = 1e6 + 5;
typedef pair<int, int> PII;

struct Edge{
    int to, nxt, w;
}e[M << 1];
int head[N << 1], st[N << 1], cnt = 0;
int dist[N << 1];
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c}, head[a] = cnt;
    return ;
}

int n, m;
void dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s}); // {dis, node}
    q.push({0, s + n});
    while(!q.empty()) {
        auto temp = q.top();
        q.pop();
        int t = temp.second, t_dis = temp.first; 
        if(st[t] == 1) continue;
        st[t] = 1;
        for(int i = head[t]; i != 0; i = e[i].nxt) {
            int j = e[i].to;
            if(dist[j] > t_dis + e[i].w) {
                dist[j] = t_dis + e[i].w;
                q.push({dist[j], j});
            }
        }
    }
    return ;
}
int main() {

    cin >> n >> m;
    for(int i = 0, a, b, c; i < m; i++) {
        scanf("%d%d%d", &a, &b ,&c);
        add(a, b, c);
        add(b + n, a + n, c);
    }
    ll ans = 0;
    dijkstra(1);
    for(int i = 2; i <= n; i++) ans += dist[i];
    for(int i = 2 + n; i <= n << 1; i++) ans += dist[i];
    printf("%lld", ans);
    return 0;
}