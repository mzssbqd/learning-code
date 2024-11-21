#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    deque<int> q;
    for(int i=0,a;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        while(!q.empty() && arr[q.back()]>arr[i]) q.pop_back();//maintain monotonicity
        if( i-k == q.front()) q.pop_front();//maintain correct scope
        q.push_back(i);
        cout<<arr[q.front()]<<endl;
    }
    return 0;
} 