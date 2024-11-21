#include <iostream>
using namespace std;
typedef long long ll;
ll exgcd(ll a ,ll b ,ll& x ,ll& y)
{
    if(!b)
    {
        x = 1 ,y = 0;
        return a;
    }
    ll d = exgcd(b , a % b , y , x);
    y -= a / b * x;
    return d;
}

void solve()
{
    ll a , b , c , x , y;
    cin >> a >> b >> c;
    ll d = exgcd(a , b , x , y);
    x = x / d * c;
    y = y / d * c;
    ll k1,k2;
    k1 = ((1 - x) / b + 1);
    int min_x = x - b * k1;
    int max_y = y - a * k1;
    k2 = ((1 - y) / a + 1);
    int min_y = y - a * k2;
    int max_x = x - b * k2;
    if(max_y < 0)
    {
        printf("%lld %lld" , min_x , min_y);
    } 
    
}
int main()
{
    ll n;
    cin >> n;
    while(n--) solve;
    return 0;
}