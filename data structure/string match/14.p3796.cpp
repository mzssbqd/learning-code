/*************************************************************************
	> File Name: 14.p3796.cpp
	> Author:mzssbqd 
	> Mail: 
	> Created Time: Fri 22 Nov 2024 07:19:34 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 20000
const int MAX_L = 1e6;
struct Node {
    int fail;
    int next[26];
    vector<int> ind;
}ac[MAX_N + 5];
int node_cnt = 1, root = 1;
char ts[MAX_L + 5], t[200][75];
int tcnt[200];
 int getNode(){
    ++node_cnt;
    ac[node_cnt].fail = 0;
    for(int i = 0; i < 26; i++) {
        ac[node_cnt].next[i] = 0;
    }
    ac[node_cnt].ind.clear();
    return node_cnt;
}

void insert(char *s, int k) {
    int p = root;
    for(int i = 0; s[i]; i++) {
        int ind = s[i] -'a';
        if(ac[p].next[ind] == 0) ac[p].next[ind] = getNode();
        p = ac[p].next[ind]; 
    }
    ac[p].ind.push_back(k);
    return ;
}

void build_ac() {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(ac[cur].fail != 0) { //3. vector数组优化
            int p = ac[cur].fail;
            ac[cur].ind.insert(ac[cur].ind.end(), ac[p].ind.begin(), ac[p].ind.end());
        }
        for(int i = 0;i < 26;i++) {
            if(ac[cur].next[i] == 0) {
                ac[cur].next[i] = (ac[cur].fail == 0 ? root : ac[ac[cur].fail].next[i]); //1.线索化
                continue;
            }   
            ac[ac[cur].next[i]].fail = (ac[cur].fail == 0 ? root : ac[ac[cur].fail].next[i]); //2.fail指针匹配
            q.push(ac[cur].next[i]);
        }
    }
    return ;
}

void find_all() {
    int p = root;
    for(int i = 0; ts[i]; i++) {
        int ind = ts[i] - 'a';
        p = ac[p].next[ind];
        for_each(ac[p].ind.begin(), ac[p].ind.end(), [&](int k) {
            tcnt[k] += 1;
        });
    }
    return;
}

void init() {
    node_cnt = 0;
    root = getNode();
    fill(tcnt, tcnt + 200, 0);
    return ;
}
void solve(int n){
    init();
    for(int i = 0; i < n; i++){
        scanf("%s", t[i]);
        insert(t[i], i);
    }
    build_ac();
    scanf("%s", ts);
    find_all();
    int ans = *max_element(tcnt, tcnt + n);
    printf("%d\n", ans);
    for(int i = 0; i < n; i++) {
        if(tcnt[i] == ans) printf("%s\n", t[i]);
    }
    return ;
}
int main(){
    int n;
    while(~scanf("%d", &n)){
        if(n == 0) break;
        solve(n);
    }
    return 0;
}

