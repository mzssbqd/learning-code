#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
typedef long long ll;
stack<long long> st;
void pop()
{
    if(st.empty()) cout<<"Empty"<<endl;
    else st.pop(); 
    return;
}
int main()
{
    char s[100];
    ll n;
    scanf("%lld",&n);
    for(ll k=0,m;k<n;k++)
    {
        scanf("%lld",&m);
        for(ll i=0,t;i<m;i++)
        {
            scanf("%s",s);
            switch(s[2])
            {
                case 's':
                {
                     scanf("%lld",&t);
                    st.push(t);
                }break;
                case 'p':
                {
                    pop();
                }break;
                case 'e':
                {
                    if(st.empty()) printf("Anguei!\n");
                    else printf("%lld\n",st.top());
                }break;
                case 'z':
                {
                    printf("%lld\n",(long long)st.size());
                }break;
            }
        }
        if(!st.empty()) st.pop();
    }
    return 0;
}