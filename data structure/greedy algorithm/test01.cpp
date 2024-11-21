#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long> arr(n);
    long long cnt=0;
    for(long long i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    for(long long i=1;i<n;i++)
    {
        if(arr[i]-arr[i-1]>1) cnt+=arr[i]-arr[i-1]-1; 
    }
    cout<<cnt<<endl;
    return 0;
}