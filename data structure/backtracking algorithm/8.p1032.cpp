
/*
1.迭代加深
    需要找到一条正确路径 , 但是如果只有一个dfs的情况下 ,可能要遍历10 ^ 6 个错误结果,那么怎么避免这种情况发生呢?
    做法:控制dfs的深度,依次加深dfs的深度
    原理:
*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Rule
{
    public:
    Rule() {}
    Rule(string a,string b):from(a),to(b) {}
    string& trans(string s)
    {

    }
    string from,to;
};

int ans = 11,ans_k;
vector<Rule> rule;
string a , b;
unordered_map<string,int> dp;
void dfs(string &now,int step)
{
    if(step + 1 > ans_k) return;
    dp[now] = step;
    if(now == b) 
    {
        ans = step;
        return;
    }

    //dfs
    for(int i = 0,I = rule.size(); i< I ;i++)
    {
        int pos = -1;
        pos = now.find(rule[i].from);
        while(pos != -1)
        {
            string changed = now;
            changed.erase(pos,rule[i].from.size());
            changed.insert(pos,rule[i].to);
            pos = now.find(rule[i].from,pos + 1);
            if (dp.find(changed) != dp.end() && dp[changed] <= step + 1)
                continue;
            dfs(changed, step + 1);
        }
    }
}
int main()
{

    cin >> a >> b;
    string from , to;
    
    while (cin >> from >> to) rule.push_back(Rule(from,to));
    for(int i = 1; i <= 10; i++)
    {
        ans_k = i;
        dp.clear();
        dfs(a,0);
        if(ans != 11) 
        {
            cout<< ans <<endl;
            return 0;
        }
    }
    cout << "NO ANSWER!" <<endl;
    return 0;
}