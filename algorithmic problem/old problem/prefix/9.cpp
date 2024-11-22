#include<iostream>
#include<vector>
using namespace std;
#define lowbit(x) ((x)&(-x))
void add(int i,int x,int n,vector<int>& arr)
{
    while(i<=n)
    {
        arr[i]+=x;
        i+=lowbit(i);
    }
}
int inqery(int i,vector<int>& arr)//1
{
    int sum=0;
    while(i>0)
    {
        sum+=arr[i];
        i-=lowbit(i);
    }
    return sum;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> arr(n+5,0);
    vector<int> L,R;
    for(int i=1,l,r;i<=m;i++)
    {
        cin>>l>>r;
        L.push_back(l),R.push_back(r);
        add(l,1,n,arr);
        add(r+1,-1,n,arr);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(inqery(i,arr)==0) ans+=1;
    }
    for(int i=0;i<m;i++)
    {
        int temp=ans;
        for(int j=L[i];j<=R[i];j++)
        {
            if(inqery(j,arr)==1) temp+=1;
        }
        cout<<temp<<endl;
    }
    return 0;
}
