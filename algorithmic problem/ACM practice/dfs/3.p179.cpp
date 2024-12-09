#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & (-x))
#define mask(n) ((1 << (n + 1)) - 2)

unordered_map<int, int> ind;
int n;
int arr[15], cnt = 3;
void print() {
    if(!cnt) return ;
    cnt -= 1;
    for(int i = 1; i <= n; i++) printf("%d ", arr[i]);
    printf("\n");
    return ;
}
int dfs(int i, int m1, int m2, int m3) {
    if(!m1) { print(); return 1;}
    int ans = 0;
    for(int k = m1; k; k -= lowbit(k)) {
        int j = ind[lowbit(k)];
        if(m2 & (1 << (i + j - 1)) && m3 & (1 << (i - j + n))) {
            arr[i] = j;
            ans += dfs(i + 1, 
            m1 ^ (1 << j),
            m2 ^ (1 << (i + j -1)),
            m3 ^ (1 << (i - j + n)));
        }
    }
    return ans;
}
int main() {
    cin >> n;
    for(int i = 0; i <= n; i++) ind[1 << i] = i;
    cout << dfs(1, mask(n), mask(2 * n - 1), mask(2 * n - 1)) << endl;
    return 0;
}