#include <iostream>
using namespace std;

const int MAX_N = 4e6;

int node[MAX_N + 5][2], node_cnt = 1, root = 1;
inline int getNode() { return ++node_cnt; } 

void insert(int x) {
    int p = root;
    for(int i = 30; i >= 0; i--) {
        int ind = !!(x & (1 << i));
        if(node[p][ind] == 0) node[p][ind] = getNode();
        p = node[p][ind];
    }
    return ;
}

int query(int x) {
    int p = root, ans = 0;
    for(int i = 30, flag; i >= 0; i--) {
        flag = 0;
        int ind = !!(x & (1 << i));
        if(node[p][1 - ind] != 0) ind = 1 - ind, flag = 1;
        if(flag == 1) ans |= (1 << i);
        p = node[p][ind];
    }
    return ans;
}
int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 0, a; i < n; i++) {
        cin >> a;
        insert(a);
        ans = max(ans, query(a));
    }
    cout << ans << endl;
    return 0;
}