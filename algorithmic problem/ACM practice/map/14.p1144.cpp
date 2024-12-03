#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5, M = 2e6 + 5, mod = 100003;
typedef pair<int, int> PII;

struct Edge{
    int to, nxt, w;
}e[2 * M];
int head[N], st[N], cnt = 0;
int dist[N], d[N], num[N];
void add(int a, int b,int c) {
    e[++cnt] = {b, head[a], c}, head[a] = cnt;
    return ;
}

int n, m;
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    num[1] = 1;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1}); // {dis, node}
    while(!q.empty()) {
        auto temp = q.top();
        q.pop();
        int t = temp.second, t_dis = temp.first; 
        if(st[t] == 1) continue;
        st[t] = 1;
        for(int i = head[t]; i != 0; i = e[i].nxt) {
            int j = e[i].to;
            if(dist[j] >= t_dis + e[i].w) {
                dist[j] = t_dis + e[i].w;
                num[j] = (num[j] + num[t]) % mod;
                q.push({dist[j], j});
            }
        }
    }
    return ;
}
int main() {

    scanf("%d%d", &n, &m);
    for(int i = 1, a, b; i <= m; i++) {
        scanf("%d%d", &a, &b);
        add(a, b, 1), add(b, a, 1);
    }
    dijkstra();
    for(int i = 1; i <= n; i++) 
    {
        printf("%d\n", num[i] % mod);
    }
    return 0;
}