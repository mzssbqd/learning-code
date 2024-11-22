#include<iostream>
#include<vector>
#define lowbit(x) ((x)&(-x))
using namespace std;
void add(int i,int x,vector<long long>& c)
{
    while(i<=c.size())
    {
        c[i]+=x;
        i+=lowbit(i);
    }
    return;
}
long long inqery(int x,vector<long long>& c)
{
    long long sum=0;
    while(x>0)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int n,w;
    cin>>n>>w;
    vector<long long> c(n+1,0);
    for(int i=1,a,b;i<=w;i++)
    {
        char scode;
        cin>>scode;
        switch(scode)
        {
            case 'x':
            {
                cin>>a>>b;
                add(a,b,c);
            }break;
            case 'y':
            {
                cin>>a>>b;
                cout<<inqery(b,c)-inqery(a-1,c)<<endl;
            }break;
        }
    }
    return 0;
}