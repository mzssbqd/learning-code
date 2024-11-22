#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> arr(n+2,-1),l(n+2,0),r(n+2,0);
    for(int i=1;i<n+1;i++) cin>>arr[i];
    stack<long long> s;
    for(int i=1;i<n+2;i++)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            r[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=arr.size()-1;i>=0;i--)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            l[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    long long max_area=-1;
    for(int i=1;i<n+1;i++)
    {
        max_area=max(max_area,arr[i]*(r[i]-l[i]-1));
    }
    cout<<max_area<<endl;
    return 0;
}