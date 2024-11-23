
//单模匹配问题

#include <iostream>
#include <string>
using namespace std;
#define TEST(func , s , t)\
{\
    cout << #func << "(" << s << "," << t <<")" << " = "<<func(s,t) << endl;\
} 
int brute_force(const string &s,const string &t)
{
    for(int i = 0 , I = s.size(); i < I ; i++)
    {
        int flag = 1;
        for(int j = 0;t[j];j++)
        {
            if(s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if(flag == 1) return i;
    }
    return -1;
}


int main()
{
    string a , b;
    while(cin >> a >> b)
    {
        TEST(brute_force , a , b);
    }
    return 0;
}