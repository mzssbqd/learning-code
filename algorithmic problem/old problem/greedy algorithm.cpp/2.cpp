#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n),add(n),ind(n);
    int ave=0;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        if(i==0) add[i]=arr[i];
        else add[i]+=add[i-1];

    }
    ave=add[add.size()-1]/n;
    int k=0,ind=0;
    while(k<=n)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]>arr[ind]) ind = i;
        }
    }
    return 0;
}