#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
const int M = 2e5 + 10;
typedef pair<int, int> PII;
struct Edge{
    int to, nxt, w;
}e[M];
int head[N], st[N], dis[N], cnt = 0;
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c}, head[a] = cnt;
}
int n, m, s;

void dijkstra() {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s}); // {dis, node}
    while(!q.empty()) {
        auto f = q.top();
        q.pop();
        int t = f.second, t_dis = f.first;
        if(st[t] == 1) continue;
        st[t] = 1;
        for(int i = head[t]; i != 0; i = e[i].nxt) {
            int j = e[i].to;
            if(dis[j] > t_dis + e[i].w) {
                dis[j] = t_dis + e[i].w;
                q.push({dis[j], j});
            }
        }
    }
    return ;
}
int main() {
    cin >> n >> m >> s;
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    dijkstra();
    for(int i = 1; i <= n; i++ ){
        printf("%d ", dis[i]);
    }
    return 0;
}
