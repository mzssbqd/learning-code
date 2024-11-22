#include<iostream>
using namespace std;
#define MAX_N 100
int dp[MAX_N + 5];
int n;
int primes[MAX_N+5],rs[MAX_N+5],cnt = 0;

void get_primes(int x)
{
    for(int i = 2; i <= x/i; i++)
    {
        if(rs[i] == 0) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= x;i++)
        {
            rs[primes[j] * i]  = 1;
            if(i % primes[j] == 0) break;
        }
    }
    return;
}


int binary_find(int x)
{
    int r = 0, l = cnt, mid;
    while(r < l)
    {
        mid =(l + r + 1)>>1;
        if(primes[mid] < x) r = mid;
        else l = mid;
    }
    return r;
}
int main()
{

    cin>>n;
    get_primes(n);
    dp[0] = 0;
    for(int i = 2;i <= n;i++)
    {
        int x = binary_find(i);
        dp[i] = dp[primes[x]] + 1;
        if(x + 1 <= cnt &&i == primes[x + 1]) dp[i] += 1;
    }
    cout<<dp[n]<<endl;
    return 0;
}