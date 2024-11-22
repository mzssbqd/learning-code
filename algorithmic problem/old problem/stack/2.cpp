#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    deque<int> max_q,min_q;
    for(int i=0;i<n;i++)
    {
        while(!min_q.empty() && arr[min_q.back()]>arr[i]) min_q.pop_back();
        min_q.push_back(i);
        if(i-min_q.front()==k) min_q.pop_front();
        if(i>=k-1) cout<<arr[min_q.front()]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        while(!max_q.empty() && arr[max_q.back()]<arr[i]) max_q.pop_back();
        max_q.push_back(i);
        if(i-max_q.front()==k) max_q.pop_front();
        if(i>=k-1) cout<<arr[max_q.front()]<<" ";
    }

    return 0;
}