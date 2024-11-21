#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main()
{
    int n,p,h,m;
    cin>>n>>p>>h>>m;
    set<pair<int,int>> s;
    vector<int> arr(n+1,0);
    arr[1]=h;
    for(int i=0,l,r;i<m;i++)
    {
        cin>>l>>r;
        if(l>r) swap(l,r);
        if(s.find({l,r})!=s.end()) continue;
        arr[l+1]-=1;
        arr[r]+=1;
        s.insert({l,r});
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=arr[i];
        cout<<sum<<endl;
    }
    return 0;
}