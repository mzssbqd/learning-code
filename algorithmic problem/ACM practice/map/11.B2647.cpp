    #include <iostream>
    #include <cstring>
    #include <algorithm>
    using namespace std;
    const int N = 110, M = 4510, INF = 1e9;

    int g[N][N];
    int n, m;

    void floyd() {
        for(int k = 1; k <= n; k++) 
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        return ;
    }
    int main() {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                g[i][j] = INF;
            }
        }
        while(m--) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            g[a][b] = min(g[a][b], w);
            g[b][a] = min(g[b][a], w);
        }
        floyd();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                printf("%d ", g[i][j]);
            }
            printf("\n");
        }
        return 0;
    }