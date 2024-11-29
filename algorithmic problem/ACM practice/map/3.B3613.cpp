#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
const int N = 5e5 + 5;

vector<set<int>> s(N);
int n, m;


void slove() {
    cin >> n >> m;
    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v);
        s[u].insert(v);
    }
    for(int i = 0; i < N; i++) {
        if(!s[i].empty()) {
            cout << i;
            for(auto k : s[i]) cout <<" "<< k << " ";   
        }
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