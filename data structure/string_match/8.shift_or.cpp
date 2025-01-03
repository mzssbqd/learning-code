#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define TEST(func , s , t)\
{\
    cout << #func << "(" << s << "," << t <<")" << " = "<<func(s,t) << endl;\
} 

int shift_and(const string &s , const string &t)
{
    int code[256], tlen = t.size();
    for(int i = 0 ;i < 256 ;i++) code[i] = ~0;
    ll p = (1 << tlen) - 1;
    for(int i = 0 ; i < tlen;i++) code[t[i]] &= ~(1 << i);
    for(int i = 0 ,I = s.size() ; i < I ; i++)
    {
        p = ((p << 1) | code[s[i]]);
        if((p & (1 << (tlen - 1))) == 0) return i - tlen + 1;  
    }

    return -1;
}
int main()
{
    string a , b;
    while(cin >> a >> b)
    {
        TEST(shift_and , a , b);
    }
    return 0;
}