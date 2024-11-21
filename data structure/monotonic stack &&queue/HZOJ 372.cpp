#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    deque<int> aq,bq;
    int i=1;
    for(;i<=n;i++)
    {
        while(!aq.empty() && a[aq.back()]>a[i]) aq.pop_back();
        while(!bq.empty() && b[bq.back()]>b[i]) bq.pop_back();
        aq.push_back(i);
        bq.push_back(i);
        if(aq.size()!=bq.size()) break;
    }
    cout<<i-1<<endl;
    return 0;
}