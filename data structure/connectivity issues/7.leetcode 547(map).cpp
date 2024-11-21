//https://leetcode.cn/problems/number-of-provinces/
/*

class Unionset
{
    public:
    Unionset(int n ):fa(n+1)
    {
        for(int i=0;i<=n;i++) fa[i]=i;
    }
    int get(int a)
    {
        return fa[a] = (fa[a]==a ? a:get(fa[a]));
    }
    void merge(int a,int b)
    {
        fa[get(a)]=get(b);
        return;
    }
    vector<int> fa;
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Unionset u(n*n);
        for(int i=0;i < n ;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(isConnected[i][j]) u.merge(i,j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(u.get(i)==i) ans+=1;
        }
        return ans;
    }
};

*/