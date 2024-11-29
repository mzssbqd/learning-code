#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
const int M = 5e5 + 10;
struct Edge{
    int to, nxt;
}e[M];
int head[N], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]}, head[a] = cnt;
    return;
}
int arr[N], a_cnt = 0;
int n, m, a, b;
void init() {
    for(int i = 0; i <= n; i++) {
        head[i] = 0;
    }
    cnt = 0;
    return ;
}
void slove() {
    init();
    
    cin >> n >> m;
    while(m--) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = head[i]; j != 0; j = e[j].nxt) {
            arr[a_cnt++] = e[j].to;
        }
        if(a_cnt == 0) 
        {
            printf(" \n");
            continue;
        }
        sort(arr, arr + a_cnt);
        for(int k = 0; k < a_cnt; k++) printf("%d ", arr[k]);
        a_cnt = 0;
        printf("\n");
    }
    return ;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        slove();
    }
    return 0;
}