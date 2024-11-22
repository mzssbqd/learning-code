#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++) 
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    deque<int> q;
    q.push_back(0);
    int sum=arr[1];
    for(int i=1;i<=n;i++)
    {
        sum=max(sum,arr[i]-arr[q.front()]);
        while(!q.empty() && arr[q.back()]>arr[i]) q.pop_back();
        q.push_back(i);
        if(i-q.front()>=m) q.pop_front();
    }
    cout<<sum<<endl;
    return 0;
}