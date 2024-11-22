#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;
class id
{
    public:
    int time;
    int id;
};
int main()
{
    int n,d,k;//d:range k:size
    cin>>n>>d>>k;
    vector<id> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].time>>a[i].id;
    }
    sort(a.begin(),a.end(),[&](id i,id j)->bool
    {
        return i.time<j.time;
    });
    unordered_map<int,int> m;
    set<int> s;
    int l=0;
    for(int r=1;r<=n;r++)
    {
        if(r-l>=d)
        {
            m[a[l].id]-=1;
            l+=1;
        }
        m[a[r-1].id]+=1;
        cout<<a[r-1].id<<" : "<<m[a[r-1].id]<<endl;
        if(m[a[r-1].id]>=k) s.insert(a[r].id);
    }
    while(!s.empty())
    {
        cout<<*s.begin()<<endl;
        s.erase(s.begin());
    }
    return 0;
}