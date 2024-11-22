#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto& x:arr) cin>>x;
    deque<int> q;
    for(int i=0;i<n;i++)
    {
        while(!q.empty() && arr[q.back()] < arr[i]) q.pop_back();
        q.push_back(i);
        if(i-q.front() == k) q.pop_front();
        if(i >=  k-1 ) cout<<arr[q.front()]<<endl;
    }
    return 0;
}