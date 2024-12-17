#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 55;
int g[N][N];
int degree[N];
int n;
void euler(int color) {
    for(int i = 1; i <= 50; i++) {
        if(g[color][i]) {
            g[color][i] -= 1, g[i][color] -= 1;
            cout << color << " " << i << endl;
            euler(i);
        }
    }
    return ;
}
int main() {
    int T, cnt = 0; cin >> T;
    while(T--) {
        cnt++;
        if(cnt != 1) cout << endl;
        cout << "Case #" << cnt << endl;
        memset(g, 0, sizeof g);
        memset(degree, 0, sizeof degree);
        cin >> n;
        int color = 1;
        for(int i = 0, a, b; i < n; i++) {
            cin >> a >> b;
            g[a][b] += 1, g[b][a] += 1;
            degree[a] += 1, degree[b] += 1;
            color = a;
        }
        int flag = 1;
        for(int i = 1; i <= 50; i++) {
            if(degree[i] % 2 == 0) continue;
            else {
                cout << "some beads may be lost" << endl;
                flag = 0;
                break;
            }
        }
        if(flag == 1) euler(color);
    }
    return 0;
}