#include <iostream>
using namespace std;
typedef long long ll;
ll c[2010][2010];
int t, k = 1;
void init() {
    for(int i = 0; i <= 2005; i++) {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
    }
    return ;
}

int main() {
    init();
    int a, b;
    cin >> t >> k;
    init();
    c[0][0] = 0;
    for(int i = 0; i <= 2005; i++) c[i][0] = c[0][i] = 0;
    for(int i = 1; i <= 2005; i++) {
        for(int j = 1; j <= 2005; j++) {
            if(j > i) c[i][j] = 0;
            else c[i][j] = (1 - !!(c[i][j] % k));
            c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
        }
    }
    while(t--) {
        scanf("%d%d", &a, &b);
        int cnt = c[a][b];
        printf("%d\n", cnt);
    }
    return 0;
}