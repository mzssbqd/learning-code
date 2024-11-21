//https://hydro.ac/d/AHUACM2024/p/P1111

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Unionset
{
    public:
    Unionset(int n):fa(n+1)
    {
        for(int i=0;i<=n;i++) fa[i]=i;
    }
    int get(int x)
    {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a,int b)
    {
        fa[get(a)] = get(b);
    }
    vector<int> fa;
};
struct Data
{
    public:
    int x,y,t;
};
int n,m;
bool check(int mid,vector<Data> arr)
{
    Unionset u(n);
    for(int i=0;i<=mid;i++)
    {
        u.merge(arr[i].x,arr[i].y);
    }
    for(int i=1;i<n;i++)
    {
        if(u.get(i)!=u.get(i+1)) return false;
    }
    return true;
}
int binary_find(vector<Data> arr)
{
    int r=0,l=m,mid;
    while(r<l)
    {
        mid=(l+r)/2;
        if(check(mid,arr) == 0) r=mid + 1;
        else l=mid;
    }
    return l;
}
int main()
{
    cin>>n>>m;
    vector<Data> arr(m);
    for(int i=0;i<m;i++)
    {
        cin>>arr[i].x>>arr[i].y>>arr[i].t;
    }
    sort(arr.begin(),arr.end(),[&](Data i,Data j)->bool
    {
        return i.t<j.t;
    });
    int cnt=binary_find(arr);
    if(binary_find(arr) == m) cout<<-1<<endl;
    else cout<<arr[cnt].t<<endl;
    return 0;
}