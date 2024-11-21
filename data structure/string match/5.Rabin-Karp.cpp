#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define TEST(func , s , t)\
{\
    cout << #func << "(" << s << "," << t <<")" << " = "<<func(s,t) << endl;\
} 

#define mod 9973
#define base 131
int hash_func(const string &s)
{
    int h = 0 , slen = s.size();
    for(int i = slen - 1,kcase = 1; i >= 0 ;i--)
    {
        h = (h + s[i] * kcase) % mod;
        kcase = kcase * base % mod;
    }
    return h;
}
int Rabin_Karp(const string &s,const string &t)
{
    int thash = hash_func(t);
    int nbase = 1 , tlen = t.size();
    for(int i = 0 ; i < tlen;i++) nbase = nbase * base % mod;
    int h = 0;
    for(int i = 0 , I = s.size();i < I ; i++)
    {
        h = h * base + s[i];
        if(i >= tlen) h = (h - s[i - tlen]*nbase % mod + mod) % mod;
        if(i + 1 < tlen) continue;
        if(h != thash) continue;
        //cout << equal(s.begin() + i - tlen + 1,s.begin() + i + 1,t.begin()) <<endl;
        if(equal(s.begin() + i - tlen + 1,s.begin() + i + 1,t.begin())) return i - tlen + 1;
    }
    return -1;
}


int main()
{
    string a , b;
    while(cin >> a >> b)
    {
        TEST(Rabin_Karp , a , b);
    }
    return 0;
}