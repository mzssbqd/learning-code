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
    }
    int ans=-10e4,sum=0;
    for(int i=1;i<=n;i++)
    {
        
        if(sum>=0) sum+=arr[i];
        else sum=arr[i];ans=sum;
    }
    cout<<ans<<endl;
    return 0;
}