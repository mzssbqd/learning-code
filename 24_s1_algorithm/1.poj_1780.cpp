#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int num[N]; //储存每个节点需要添加的下一位数字
int st_edge[10 * N], top_s; // 储存边的栈
char ans[10 * N]; int top_a; // 储存答案的栈
int m; // 位数

void no_dfs(int v) {
    int edge;
    while(num[v] < 10) {
        edge = 10 * v + num[v], num[v] += 1;
        st_edge[top_s++] = edge;
        printf("%02d -> ", v);
        v = edge % m;
        printf("%02d: edge = %03d\n", v, edge);
    }
    return ;
}
int main() { 
    int n, edge;
    while(~scanf("%d", &n) && n != 0) {
        top_s = top_a = edge = 0;
        m = 1;
        for(int i = 0; i < n - 1; i++) m *= 10;
        for(int i = 0; i < m; i++) num[i] = 0;
        no_dfs(0);
        while(top_s) {
            edge = st_edge[--top_s];
            ans[top_a++] = edge % 10 + '0';
            //printf("dfs : \n");
            no_dfs(edge / 10);
        }
        for(int i = 1; i < n; i++) printf("0");
        while(top_a) printf("%c", ans[--top_a]);
        printf("\n");
    }
    return 0;
}