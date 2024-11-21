#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int l;
    cin>>l;
    vector<int> arr(l+1,1);
    int begin,end,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>begin>>end;
        for(int j=begin;j<=end;j++)
        {
            arr[j]=0;
        }
    }
    int cnt=0;
    for(int i=0;i<=l;i++) cnt+=arr[i];
    cout<<cnt<<endl;
}