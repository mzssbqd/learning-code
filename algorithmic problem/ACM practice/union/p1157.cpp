#include<iostream>
#include<vector>
using namespace std;

int n , r;

int print(vector<int> arr)
{
    for(int i = 0;i < r;i++)
    {
        printf("%3d",arr[i]);
    }
    printf("\n");
    return 0;
}
void dfs(int k,int ind,vector<int> arr)
{
    if(k == r)
    {
        print(arr);
        return;
    }
    for(int i = ind; i <= n; i++)
    {
        arr[k] = i;
        dfs(k + 1,i + 1,arr);
    }
    return;
}
int main()
{

    cin >> n >> r;
    vector<int> arr(r);
    dfs(0 , 1,arr);
    return 0;
}
