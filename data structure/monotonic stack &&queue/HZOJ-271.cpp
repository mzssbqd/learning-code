#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    deque<int> most,lest;
    for(int i=0;i<n;i++)
    {
        while(!lest.empty() && arr[lest.back()]>arr[i]) lest.pop_back();
        lest.push_back(i);
        if(i-lest.front()==k) lest.pop_front();
        if(i+1 < k) continue;
        if(i!=n-1)cout<<arr[lest.front()]<<" ";
        else cout<<arr[lest.front()];
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        while(!most.empty() && arr[most.back()]<arr[i]) most.pop_back();
        most.push_back(i);
        if(i-most.front()==k) most.pop_front();
        if(i+1 < k) continue;
        if(i!=n-1)cout<<arr[most.front()]<<" ";
        else cout<<arr[most.front()];
    }
    
    return 0;
}