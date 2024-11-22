//https://leetcode.cn/problems/surrounded-regions/




/*
class Unionset
{
    public:
    Unionset(int n) : fa(n+1)
    {
        for(int i=0;i<=n;i++) fa[i]=i;
    }
    int get(int x)
    {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a,int b)
    {
        if(get(a) == get(b)) return;
        fa[get(a)] = get(b);
        return;  
    }
    vector<int> fa;
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        Unionset u(m*n);
        for(int i=0 ; i < m;i++)
        {
            for(int j=0;j < n;j++)
            {
                int ind= i*n + j + 1;
            }
        }
    }
};



*/