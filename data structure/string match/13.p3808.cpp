#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 1e6;

int node[MAX_N + 5][26] = {0};
int cnt[MAX_N + 5] = {0}, node_cnt = 0, root = 1;
char s[MAX_N + 5];

int get_node()
{
    return ++node_cnt;
}

void insert(string a)
{
    int p = root;
    for(int i = 0; a[i]; i++)
    {
        int ind = a[i] - 'a';
        if(node[p][ind] == 0) node[p][ind] = get_node();
        p = node[p][ind];
    }
    cnt[p] += 1;
    return;
}

queue<int> q;
int fail[MAX_N + 5] = {0};
void build_ac()
{
    q.push(root);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < 26; i++){
            if(node[cur][i] == 0){
                node[cur][i] = (fail[cur] == 0 ? root : node[fail[cur]][i]); //线索化
                continue;
            }
            fail[node[cur][i]] = (fail[cur] == 0 ? root : node[fail[cur]][i]);//ac
            q.push(node[cur][i]);
        }
    }
    return;
}
//int que[MAX_N + 5];
// void build(){
//     int head = 0, tail = 0, p;
//     que[tail++] = root;
//     while(head < tail){
//         int cur = que[head++];
//         for(int i = 0; i < 26; i++){
//             if(node[cur][i] == 0){
//                 if(fail[cur] == 0) node[cur][i] = root;
//                 else node[cur][i] = node[fail[cur]][i];
//                 continue;
//             }
//             p = fail[cur];
//             if(p == 0) p = root;
//             else p = node[fail[cur]][i];
//             fail[node[cur][i]] = p;
//             que[tail++] = node[cur][i];
//         }
//     }
//     return;
// }
int find_all()
{
    int ans = 0, p = root, t;
    for(int i = 0; s[i]; i++)
    {
        int ind = s[i] - 'a';
        p = node[p][ind];
        t = p;
        while(t && t != -1){
            ans += cnt[t];
            cnt[t] = -1;
            t = fail[t];
        }
    }
    return ans;
}
int main()
{
    int n;
    string a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        insert(a);
    }
    build_ac();
    scanf("%s", s);
    cout << find_all() << endl;
    return 0;
}