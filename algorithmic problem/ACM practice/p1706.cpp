#include<iostream>
#include<unordered_map>
using namespace std;
#define lowbit(x) ((x) & (-x))
unordered_map<int,int> ind;

int arr[10];

void print(int n)
{
    for(int i = 1;i <= n; i++ )
    {
        printf("%5d",arr[i]);
    }
    printf("\n");
}
void dfs(int mask,int k,int n)
{
    if(mask == 0)
    {
        print(n);
        return;
    }
    for(int i = mask; i ;i -= lowbit(i))
    {
        int to = ind[lowbit(i)] ,next_t = mask ^(1 << to);
        arr[k] = to;
        dfs(next_t ,k + 1, n);
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i <= n; i++) ind[1 << i] = i;
    dfs(((1 << (n + 1)) -2), 1 , n);
    return 0;
}