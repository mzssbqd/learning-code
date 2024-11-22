#include<iostream>
#include<set>
using namespace std;
typedef pair<int,int> PII;
int main()
{
    int n;
    set<PII> s;
    cin>>n;
    for(int i=0,a;i<n;i++)
    {
        cin>>a;
        s.insert(PII(a,i));
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int min1,min2;
        min1=s.begin()->first;
        s.erase(s.begin());
        min2=s.begin()->first;
        s.erase(s.begin());
        ans+=min1+min2;
        s.insert(PII(min1+min2,n+i));
    }
    cout<<ans<<endl;
    return 0;
}