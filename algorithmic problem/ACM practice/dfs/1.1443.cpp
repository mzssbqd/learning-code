#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 410;
int dis[N][N];
int dir[8][2] = {
    {1,2} , {2,1},
    {-1,2}, {-2,1},
    {1,-2}, {2,-1},
    {-1,-2}, {-2,-1}
};
struct Node{
    int x, y;
};
int n, m, x, y;
Node q[100000];
void bfs() {
    int tt, hh;
    hh = tt = 0;
    q[tt++] = {x, y};
    dis[x][y] = 0;
    while(hh < tt) {
        auto cur = q[hh++];
        int x1 = cur.x, y1 = cur.y;
        for(int i = 0; i < 8; i++) {
            int dx = x1 + dir[i][0], dy = y1 + dir[i][1];
            if(dx < 1 || dx > n) continue;
            if(dy < 1 || dy > m) continue;
            if(dis[dx][dy] != -1) continue;
            dis[dx][dy] = dis[x1][y1] + 1;
            q[tt++] = {dx, dy};
        }
    }
    return ;
}
int main() {
    memset(dis, -1, sizeof dis);
    cin >> n >> m >> x >> y;
    bfs();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) printf("%d ", dis[i][j]);
        printf("\n");
    }
    return 0;
}