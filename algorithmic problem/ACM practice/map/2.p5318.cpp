#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5, M = 1e6 + 5;

struct Edge{
    int to, nxt;
}e[M];
int head[N], cnt = 0;
bool st[N];
int n, m;

void add(int a, int b) {
    e[++cnt] = {b, head[a]}, head[a] = cnt;
    return ;
}

void dfs(int root) {
    printf("%d ", root);
    for(int i = head[root]; i != 0; i = e[i].nxt) {
        int j = e[i].to;
        if(!st[j]) dfs(j);
        st[j] = 1;
    }
    return ;
}
int main() {
    cin >> n >> m;
    int a, b, beg = N;
    while(m--) {
        cin >> a >> b;
        beg = min(beg, a);
        add(a, b);
    }
    dfs(beg);
    return 0;
}