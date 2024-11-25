/*************************************************************************
	> File Name: 22.p1470.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun Nov 24 20:08:34 2024
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

const int MAX_N = 2e5;
int node[MAX_N + 5][26], node_cnt = 1, root = 1;
int val[MAX_N + 5] = {0}, dp[MAX_N + 5];
char s[MAX_N + 5];
string t;
inline int getNode() { return ++node_cnt; }

void insert(char *s) {
    int p = root;
    for(int i = 0; s[i]; i++) {
        int ind = s[i] - 'A';
        if(node[p][ind] == 0) node[p][ind] = getNode();
        p = node[p][ind];
    }
    val[p] = 1;
    return ;
}

void mask(int beg, string &u) {
    int p = root;
    for(int i = beg; u[i]; i++) {
        int ind = u[i] - 'A';
        p = node[p][ind];
        if(p == 0) break;
        if(val[p] == 1) dp[i + 1] = 1;
    }
    return ;
}
int main() {
    while(~scanf("%s", s)) {
        if(s == ".") break;
        insert(s);
    }
    string t, k;
    t = "";
    while(cin >> k) {
        t += k;
    } 
    dp[0] = 1;
    int ans = 0, i = 0;
    for(; t[i]; i++) {
        if(dp[i] == 0) continue;
        ans = i;
        mask(i, t);
    }
    if(dp[i + 1] == 1) ans = i;
    cout << ans << endl;
    return 0;
}
