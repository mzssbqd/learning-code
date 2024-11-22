#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int w,n,cnt=0;  
    cin>>w>>n;
    vector<int> s(n);
  
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s.begin(),s.end());
    int i=0,j=s.size()-1;
    while(i<=j)
    {
        if(j!=i && s[i]+s[j]<=w)
        {
            i+=1,j-=1;
            cnt+=1;
        }
        else
        {
            j-=1;
            cnt+=1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}