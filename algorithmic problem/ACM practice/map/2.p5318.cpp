#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5, M = 1e6 + 5;

struct Edge{
    int to, nxt;
}e[M];
int head[N], cnt = 0;
bool st[N];
int arr[N], arr_cnt = 0;
int n, m;

void add(int a, int b) {
    e[++cnt] = {b, head[a]}, head[a] = cnt;
    return ;
}

void dfs(int root) {
    st[root] = 1, arr_cnt = 0;
    printf("%d ", root);
    for(int i = head[root]; i != 0; i = e[i].nxt) {
        int j = e[i].to;
        arr[arr_cnt++] = j;
    }
    for(int i = 0; i < arr_cnt; i++) {
        if(st[i] == 0) dfs(arr[i]);
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