#include <iostream>
using namespace std;
const int N = 1010;
int D[N][N];

void modify(int x1, int y1, int x2, int y2) {
    D[x1][y1] += 1, D[x2 + 1][y2 + 1] += 1;
    D[x2 + 1][y1] -= 1, D[x1][y2 + 1] -= 1;
    return ;
}
int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int x1, x2, x3, x4;
        cin >> x1 >> x2 >> x3 >> x4;
        modify(x1, x2, x3, x4);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            //a[i][j] = D[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1]; 
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}