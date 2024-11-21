#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0),result;
    for(int i=1;i<=n;i++) 
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<arr[r]-arr[l-1]<<endl;
    }
    return 0;
}