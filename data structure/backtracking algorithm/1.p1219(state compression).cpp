//source : https://www.luogu.com.cn/problem/P1219
/*
1.问题状态搜索树
2.先实现,在优化
3.搜索剪纸
*/


/*

1.问题搜索树: 排列形枚举
2.状态表示: 用二进制数来表示一个数字被使用---->状态压缩
3.快速枚举: lowbit() --- (树状数组)
4.斜边表示
*/


/*
core point:
1.MASK(n) (1 << (n+1)) - 2 
2.lowbit(x) ((x) & (-x))  
3.mapping : 
{
unordered_map<long long,int> ind;
for(int i=0 ; i < 2 * n; i++) ind[1 << i] =i; // ind[1] = 0,ind[2] = 1, ind[4] =2, ind[8] = 3
}
4.掩码 : 111111 mask = 001000
5.切换位 : ^=mask
*/
#include<iostream>
#include<unordered_map>
using namespace std;

#define MASK(n) ((1 << (n+1)) -2 ) //6: 1111110

#define lowbit(x) ((x) & (-x))

unordered_map<long long,int> ind;

int total = 3;
int arr[20];
void print_result(int n)
{
    for(int i = 1; i <= n;i++)
    {
        if( i>1 ) cout<<" ";
        cout<<arr[i];
    }
    cout<<endl;
    total -= 1;
}
int dfs(int i, int t1, int t2, int t3,int n)
{
    if(i > n) 
    {
        if(total) print_result(n);
        return 1;
    }
    int ans = 0;
    for(int k = t1 ; k ; k -= lowbit(k))
    {
        int j = ind[lowbit(k)];
        if(t2 & (1 << (i+j-1)) && t3 & (1 << (i-j+n)))
        {
            arr[i] = j;
            ans += dfs(i + 1, t1 ^ (1 << j)
            , t2 ^ (1 << (i+j-1))
            , t3 ^ (1 << (i-j+n))
            ,n);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0 ; i < 2 * n; i++) ind[1 << i] =i;
    int ans = dfs(1 , MASK(n) , MASK(2 * n - 1) , MASK(2 * n -1),n);
    cout<< ans <<endl;
    return 0;
}