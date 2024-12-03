#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;

const int N = 110;
bitset<N> g[N];
int n;
void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            if(g[i][k]) 
                g[i] |= g[k];
    return ;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 1, temp; j <= n; j++) {
            cin >> temp;
            g[i][j] = temp;
        }
    floyd();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cout << g[i][j] << " ";
        printf("\n");
    }
        
    return 0;
}