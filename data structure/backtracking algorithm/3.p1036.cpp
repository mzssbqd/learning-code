//https://www.luogu.com.cn/problem/P1036

#include<iostream>
using namespace std;

int val[25],cnt = 0;

typedef long long ll;

bool is_primes(ll n)
{
    for(int i = 2;i<=n/i;i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

void dfs(int k, int ind, int n, int m ,ll sum)
{
    if(k == m + 1) 
    {
        if(is_primes(sum)) cnt +=1;
        return;
    }
    for(int i=ind; i<=n;i++)
    {
        dfs(k+1, i + 1, n, m ,sum+val[i]);
    }
    return;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i = 1; i <= n;i++) cin>>val[i];
    dfs(1 , 1, n, k,0);
    cout<<cnt<<endl;
    return 0;
}