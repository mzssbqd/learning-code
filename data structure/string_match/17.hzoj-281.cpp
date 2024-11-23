/*************************************************************************
	> File Name: 16.hzoj-279.cpp
	> Author:mzssbqd 
	> Mail: 
	> Created Time: Fri 22 Nov 2024 10:06:07 PM CST
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 1e6;
int node[MAX_N + 6][26], node_cnt = 1, root = 1;
int flag[MAX_N + 6];
char s[MAX_N + 5];
inline int getNode() { return ++node_cnt;}


void insert(const char* s) {
    int p = root;
    for(int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if(node[p][ind] == 0) node[p][ind] = getNode();
        p = node[p][ind];
    }
    flag[p] += 1;
    return ;
}

void find_all(const char *s) {
    int p = root, ans = 0;
    for(int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        p = node[p][ind];
        if(p == 0) break;
        ans += flag[p];
    }
    printf("%d\n", ans);
    return ;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(s);
    }
    for(int i = 0; i < m; i++) {
        scanf("%s", s);
        find_all(s);
    }
    return 0;
}