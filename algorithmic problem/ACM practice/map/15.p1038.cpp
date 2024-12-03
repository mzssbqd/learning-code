#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int N = 110;
int g[N][N];
int u[N], c[N], in[N], out[N];
int n, p;

queue<int> q;
void topsort() {
    for(int i = 1; i <= n; i++)
        if(in[i] == 0) q.push(i);
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        c[t] -= u[t];
        for(int i = 1; i <= n; i++) {
            if(g[t][i] == 0) continue;
            if(c[t] > 0) c[i] += g[t][i] * c[t]; 
            in[i] -= 1;
            if(in[i] == 0) q.push(i);
        }
    }
    return;
}
int main() {
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        c[i] = a;
        u[i] = b;
    }
    for(int i = 1; i <= p; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = w;
        in[b] += 1, out[a] += 1;
    }
    topsort();
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(out[i] == 0 && c[i] > 0) {
            printf("%d %d\n", i, c[i]);
            ans += 1;
        }
    }
    if(ans == 0) cout << "NULL" << endl;
    return 0;
}