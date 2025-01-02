/*************************************************************************
	> File Name: 2.p1341.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 10:39:39 AM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N = 260;
int g[N][N], degree[N];
int n;

void dfs(int ind) {
    cout << (char)ind;
    for(int i = 0; i <= 256; i++) {
        if(g[ind][i]) {
            g[ind][i] -= 1, g[i][ind] -= 1;
            dfs(i);
        } 
    }
    return ;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        g[a][b] = 1, g[b][a] = 1;
        degree[a] += 1, degree[b] += 1;
    }
    int ind = 0x3f3f3f3f, flag= 1;
    for(int i = 0; i <= 256; i++) {
        if(degree[i] % 2 == 0) {
            if(degree[i] != 0) ind = min(ind, i); 
            continue;
        }
        cout << "No Solution" << endl;
        flag = 0;
    }
    if(flag) dfs(ind);
    return 0;
}

