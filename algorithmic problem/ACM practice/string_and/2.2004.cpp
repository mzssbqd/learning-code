#include <iostream>
using namespace std;
const int N = 2010, INF = 1e9;

int S[N][N];
int n, m, c;

int getsum(int x1, int y1, int x2, int y2) {
    return S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
}
int main() {
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> S[i][j];
            S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }
    int sum = -INF, max_i = 1, max_j = 1;
    for(int i = 1; i + c - 1<= n; i++) {
        for(int j = 1; j + c - 1<= m; j++) {
            if(getsum(i, j, i + c - 1, j + c - 1) > sum) {
                sum = getsum(i, j, i + c - 1, j + c - 1);
                max_i = i, max_j = j;
            }
        }
    }
    printf("%d %d", max_i, max_j);
    return 0;
}