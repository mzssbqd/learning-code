#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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
int Rabin_Karp(const string &s,const vector<string> t)
{
    unordered_map<int , vector<int>> hm;
    int size = t.size();
    for(int i = 0 ; i < size; i++)
    {
        int thash = hash_func(t[i]);
        hm[thash].push_back(i);
    }
    int nbase = 1 , tlen = t[0].size(); // nbase: base 的 n倍 
    for(int i = 0 ; i < tlen;i++) nbase = nbase * base % mod;
    int h = 0;
    //core
    for(int i = 0 , I = s.size();i < I ; i++)
    {
        h = h * base + s[i]; 
        if(i >= tlen) h = ((h - s[i - tlen]*nbase) % mod + mod) % mod;
        if(i + 1 < tlen) continue;
        if(hm.find(h) == hm.end()) continue;
        //cout << equal(s.begin() + i - tlen + 1,s.begin() + i + 1,t.begin()) <<endl;
        for(int j = 0 ;j < (int)hm[h].size();j++)
        {
            if(equal(s.begin() + i - tlen + 1,s.begin() + i + 1,t[hm[h][j]].begin()))
            {
                cout <<"find : "<<t[hm[h][j]] << " in " << i - tlen + 1 <<endl;
            }
        }
    }
    return -1;
}


int main()
{
    string a , b;
    vector<string> arr;
    while(cin >> b)
    {
        if(b != "0") arr.push_back(b);
        else break;
    }
    while(cin >> a)
    {
        Rabin_Karp(a , arr);
    }
    return 0;
}