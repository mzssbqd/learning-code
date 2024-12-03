#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<double, int> PII;
const int N = 2010;
const int M = 1e5 + 10;
const int INF = 1e9;
struct Edge{
    int to, nxt;
    double w;
    bool operator<(const Edge &a) {
        return a.w > w;
    }
}e[2 * M];
int head[N], cnt = 0;
double dist[N];
bool st[N];
int n, m, A, B;
void add(int a, int b, double c) {
    e[++cnt] = {b, head[a], c}, head[a] = cnt;
    return;
}

double dijkstra() {
    for(int i = 1; i <= n; i++) dist[i] = -INF;
    dist[A] = 1;
    priority_queue<PII, vector<PII>, less<PII>> q;
    q.push({1.0, A}); // {dis, node}
    while(!q.empty()) {
        auto temp = q.top();
        q.pop();
        int t = temp.second;
        double t_dis = temp.first; 
        if(st[t] == 1) continue;
        st[t] = 1;
        for(int i = head[t]; i != 0; i = e[i].nxt) {
            int j = e[i].to;
            if(dist[j] < t_dis * e[i].w) {
                dist[j] = t_dis * e[i].w;
                q.push({dist[j], j});
            }
        }
    }
    return dist[B];
}
int main() {
    scanf("%d%d", &n, &m);
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, 1 - 0.01 * c);
        add(b, a, 1 - 0.01 * c);
    }
    scanf("%d%d", &A, &B);
    double ans = dijkstra();
    printf("%.8lf", 100 / ans);
    return 0;
}