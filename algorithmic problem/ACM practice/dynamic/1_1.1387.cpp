#include <iostream>
using namespace std;
const int N = 110;
int f[N][N], ans = 0;
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            cin >> f[i][j];
    
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            if(f[i][j]) {
                f[i][j] = min(f[i - 1][j - 1],min(f[i - 1][j], f[i][j - 1])) + 1;
                ans = max(f[i][j], ans);
            }
    cout << ans << endl;
    return 0;
}