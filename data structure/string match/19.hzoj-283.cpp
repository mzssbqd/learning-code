/*************************************************************************
	> File Name: 19.hzoj-283.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Nov 2024 06:04:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

const int MAX_N = 1e5;

char s[MAX_N + 5];
int node[MAX_N + 5][10];
int node_cnt = 1, root = 1;
int val[MAX_N + 5], child[MAX_N + 5];

int insert(const char *s) {
    int p = root, ans = 0;
    for(int i = 0; s[i]; i++) {
        int ind = s[i] - '0';
        if(node[p][ind] == 0) {
            node[p][ind] = ++node_cnt;
            child[p] += 1;
        }
        p = node[p][ind];
        ans += val[p];
    }
    val[p] += 1;
    return !(ans == 0 && child[p] == 0); 
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i= 0;i < n; i++) {
        scanf("%s", s);
        cnt += insert(s);
    }
    printf("%s", (cnt == 0 ? "YES" : "NO"));
    return 0;
}
