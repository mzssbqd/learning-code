#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    int m;
    cin>>m;
    for(int i=0,l,r;i<m;i++)
    {
        cin>>l>>r;
        cout<<arr[r]-arr[l-1]<<endl;
    }
    return 0;
}