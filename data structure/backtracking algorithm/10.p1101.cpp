#include <iostream>
using namespace std;

#define MAX_N 100


int vis[MAX_N + 5][MAX_N + 5];
int dir[8][2] = 
{
    {1 , 1} , {1 , -1},{-1 , 1},{-1 , -1},
    {1 , 0} , {0 , 1},{-1 , 0},{0 , -1}
};
char c[MAX_N + 5][MAX_N + 5];
int ans[MAX_N + 5][MAX_N + 5] = {0};
char match[8] = "yizhong";

    int n;
int get_ans(int x,int y)
{
    for(int i = 0; i < 8 ; i++)
    {
        int flag = 1;
        
        for(int j = 0; j < 7; j++)
        {
            int dx = x + dir[i][0] * j;
            int dy = y + dir[i][1] * j;
            if(c[dx][dy] != '\0' && c[dx][dy] == match[j]) continue;
            flag = 0;
            break;
        }
        if(flag == 1)
        {
            for(int j = 0; j < 7; j++)
            {
                int dx = x + dir[i][0] * j;
                int dy = y + dir[i][1] * j;
                ans[dx][dy] = 1;
            }
        }
    }
    return 0;
}
void dfs(int i , int j)
{
    if(vis[i][j] == 1) return;
    if(c[i][j] == '\0') return;
    if(c[i][j] == 'y') 
    {
        get_ans(i , j);
    }
    vis[i][j] = 1;
    dfs(i + 1 , j);
    dfs(i , j + 1);
    return;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin>>(c[i] + 1);
    }
    dfs(1 , 1);
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(ans[i][j] == 1) cout << c[i][j];
            else cout<< '*';
        }
        cout << endl;
    }
    return 0;
}