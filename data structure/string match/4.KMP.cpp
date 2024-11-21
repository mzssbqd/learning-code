#include <iostream>
#include <string>
using namespace std;
#define TEST(func , s , t)\
{\
    cout << #func << "(" << s << "," << t <<")" << " = "<<func(s,t) << endl;\
} 

int *getnext(const string& t)
{
    int tlen = t.size() , j;
    int *next = new int(tlen);
    next[0] = -1 , j = -1;
    for(int i = 1; i <= tlen ;i++)
    {
        while(j != -1 && t[i] != t[j + 1]) j = next[j];
        if(t[i] == t[j + 1]) j += 1;
        next[i] = j;
    }
    return next;
}
int KMP(const string &s,const string &t)
{
    int *next = getnext(t) , j = -1 ,tlen = t.size();
    for(int i = 0 , I = s.size();i <= I;i++)
    {
        while(j != -1 && s[i] != t[j + 1]) j = next[j];
        if(s[i] == t[j + 1]) j +=1;
        if(j == (int)t.size() - 1) return i - tlen + 1; 
    }
    return -1;
}


int main()
{
    string a , b;
    while(cin >> a >> b)
    {
        TEST(KMP , a , b);
    }
    return 0;
}