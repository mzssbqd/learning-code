//sunday
/*
黄金对齐点位



*/

#include <iostream>
#include <string>
using namespace std;
#define TEST(func , s , t)\
{\
    cout << #func << "(" << s << "," << t <<")" << " = "<<func(s,t) << endl;\
} 
int BM(const string &s,const string &t)
{
    int len[256] , n = t.size();
    for(int i = 0 ; i < 256 ; i++) len[i] = n + 1;
    for(int i = 0;t[i];i++) len[(int)t[i]] = n - i;
    for(int i = 0, I = s.size(); i + n <= I; i += len[(int)t[i + n]])
    {
        int flag = 1;
        for(int j = 0; j < n;j++)
        {
            if(s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if(flag) return i;
    }
    return -1;
}


int main()
{
    string a , b;
    while(cin >> a >> b)
    {
        TEST(BM , a , b);
    }
    return 0;
}