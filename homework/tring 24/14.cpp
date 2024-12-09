#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 1000005;

int primes[N],cnt=0;
int st[N];

int is_hui(int x) {
    int temp = x, ans = 0;
    while(temp) {
        ans = ans * 10 + (temp % 10);
        temp /= 10;
    }
    if(ans == x) return 1;
    return 0;
}
int get_primes(int n)
{
    for(int i=2;i<=N;i++)
    {
        if(st[i]==0) {
            primes[cnt++]=i;
            
            if(is_hui(i) && i > n) return i;
        }
        for(int j=0;primes[j]<=N/i;j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", get_primes(n));
    return 0;
}