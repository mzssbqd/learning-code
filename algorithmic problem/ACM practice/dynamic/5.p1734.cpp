#include<iostream>
#include<unordered_map>
using namespace std;

typedef long long ll;

#define MAX_S 1000
ll dp[MAX_S];

// ll sum_divisor(int n)
// {
//     unordered_map<int,int> primes;
//     int temp =n;
//     for(int i=2;i<=n/i;i++)
//     {
//         if(n%i == 0)
//         {
//             while(n % i == 0) 
//             {
//                 n /= i;
//                 primes[i] += 1;
//             }
//         }
//     }
//     if(n > 1) primes[n] += 1;
//     ll sum = 1;
//     for(auto x:primes)
//     {
//         int q = x.first , a= x.second;
//         ll t= 1;
//         while( a-- ) t = (t*q+1);
//         sum *= t;
//     }
//     sum-=temp;
//     return sum;
// }

ll sum_divisor(int n)
{
    ll sum=0;
    for(int i=1;i<n;i++)
    {
        if(n%i == 0) sum+=i;
    }
    return sum;
}
int main()
{
    int S;
    cin>>S;
    for(int i=1;i<=S;i++)
    {
        for(int j = S ;j>= i;j--)
        {
            dp[j] = max(dp[j - i]+sum_divisor(i),dp[j]);
        }
    }
    cout<<dp[S];
    return 0;
}