#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 400 + 10;
const int M = 1000 + 10;
struct Edge{
    int to, nxt, w, ind;
}e[M];
int head[N], dis[N], cnt = 0;
bool st[N];
void add(int a, int b, int w, int ind) {
    e[++cnt] = {b, head[a], w, ind}, head[a] = cnt;
    return ;
}
int node[N];
int n, m;
int s, t1;
int q[10000];
int spfa() {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    int hh = 0, tt = 0;
    q[tt++] = 1;
    int deep = 0;
    while(hh < tt) {
        int t = q[hh++];
        st[t] = false;
        for(int i = head[t]; i != 0; i = e[i].nxt) {
            if(node[e[i].ind == -1]) node[e[i].ind] = deep;
            int j = e[i].to, w = e[i].w;
            if(dis[j] > dis[t] + w) {
                dis[j] = dis[t] + w;
                if(!st[j]) {
                    q[tt++] = j;
                    st[j] = true;
                }
            }
        }
        deep += 1;
    }
    return dis[t1];
}
int main() {
    cin >> n >> m >> s >> t1;
    memset(node, -1, sizeof node);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        add(a, b, 1, i);
    }
    int ans = spfa();
    cout << ans << endl;
    for(int i = 0; i < m; i++) {
        if(node[i] != -1 ) printf("%d\n", node[i]);
        else printf("0\n");
    }
    return 0;
}