#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int N = 5010, M = 5e5 + 10, INF = 1e9, mod = 80112002;
struct Edge {
    int to, nxt;
}e[M];
int head[N], cnt = 0;
int st[N], dist[N] , d[N], cd[N];
int ans = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]}, head[a] = cnt;
    return ;
}

queue<int> q;
void topsort(int n) {
    for(int i = 1; i <= n; i++) {
        if(d[i] != 0) continue; 
        q.push(i);
        dist[i] = 1;
    }
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        for(int i = head[f]; i != 0; i = e[i].nxt) {
            int j = e[i].to;
            d[j] -= 1;
            dist[j] = (dist[f] + dist[j]) % mod;
            if(d[j] == 0) q.push(j);
        }
    }
    return ;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b] += 1;
        cd[a] += 1;
    }
    topsort(n);
    for(int i = 1; i <= n; i++) {
        if(cd[i] != 0) continue;
        ans = (ans + dist[i]) % mod;
    }
    printf("%d", ans % mod);
    return 0;
}