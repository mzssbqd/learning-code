#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    int sum=0,sub=0; 
    for(int i=1;i<=n-k;i++)
    {
        sum=arr[i+k]-arr[i-1];//
        if(sum>sub) sub=sum;
    }
    cout<<sub<<endl;
    return 0;
}