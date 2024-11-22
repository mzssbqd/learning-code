#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int l,m;
    cin>>l>>m;
    vector<int> arr(l+5,0);
    arr[0]=1;
    for(int i=0,x,y;i<m;i++)
    {
        cin>>x>>y;
        arr[x]-=1;
        arr[y+1]+=1;
    }
    int cnt=0;
    if(arr[0]==1) cnt+=1;
    for(int i=1;i<=l;i++)
    {
        arr[i]+=arr[i-1];
        if(arr[i]==1) cnt+=1;
    }
    cout<<cnt<<endl;
    return 0;
}