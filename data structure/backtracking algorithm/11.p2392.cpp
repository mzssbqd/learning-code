#include <iostream>
using namespace std;
#define MAX_N 20

int arr[MAX_N + 5];

int ans = 1000000000;
void dfs(int k , int n , int l ,int r)
{
    if(k == n)
    {
        ans = min(ans , max(l,r));
        return;
    }
    l += arr[k];
    dfs(k + 1 , n , l , r );
    l -= arr[k];
    r += arr[k];
    dfs(k + 1 , n , l, r );
    r -= arr[k];
    return;
}
int main()
{
    int s1[4];
    for(int i = 0 ;i < 4; i++) cin >> s1[i];
    int t = 0;
    for(int k = 0 ;k < 4; k++)
    {
        for(int i = 0;i < s1[k]; i++)
        {
            cin >> arr[i];
        }
        dfs(0 , s1[k] , 0 , 0);
        t += ans;
        ans = 100000000;
    }
    cout << t << endl;

    return 0;
}