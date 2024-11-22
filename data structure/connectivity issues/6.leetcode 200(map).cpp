//https://leetcode.cn/problems/number-of-islands/



//坐标表示:
//n*m:
//i*m + j + 1  



/*

class Unionset
{
    public:
    Unionset(int n):fa(n+1)
    {
        for(int i=0;i<=n;i++)
        {
            fa[i]=i;
        }
    }
    
        int get(int x)
        {
            return fa[x] = (fa[x]==x ? x : get(fa[x]));
        }
        void merge(int a,int b)
        {
            if(get(a) == get(b) ) return;
            fa[get(a)]=get(b);
            return;
        }
    vector<int> fa;
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        Unionset u(n*m);
        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0; j <m ;j++)
            {
                int ind=i*m + j + 1;
                if(grid[i][j] == '0') continue;
                if(j+1<m && grid[i][j+1]=='1') u.merge(ind,ind+1);
                if(i+1<n && grid[i+1][j] == '1') u.merge(ind,ind+m); 
            }
        }
        int cnt=0;
        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0; j <m ;j++)
            {
                int ind=i*m + j + 1;
                if(grid[i][j]=='1' && u.get(ind) == ind) cnt+=1; 
            }
        }
        return cnt;
    }
};

*/