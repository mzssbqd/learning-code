#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
struct Edge{
    int to, nxt, w;
}e[M];
int head[N], dis[N], cnt = 0;
bool st[N];
void add(int a, int b, int w) {
    e[++cnt] = {b, head[a], w}, head[a] = cnt;
    return ;
}
int n, m;

int q[N];
int spfa() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    int hh = 0, tt = 0;
    q[tt++] = 1;
    while(hh < tt) {
        int t = q[hh++];
        st[t] = false;
        for(int i = head[t]; i != 0; i = e[i].nxt) {
            int j = e[i].to, w = e[i].w;
            if(dis[j] > dis[t] + w) {
                dis[j] = dis[t] + w;
                q[tt++] = j;
                st[j] = true;
            }
        }
    }
    return dis[n];
}
int main() {
    cin >> n >> m;
    for(int i = 0, a, b, w; i < m; i++) {
        cin >> a >> b >> w;
        add(a, b, w);
    }
    int ans = spfa();
    if(ans == 0x3f3f3f3f) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;
}