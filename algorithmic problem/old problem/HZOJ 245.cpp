#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ans.push_back(a);
    }
    sort(ans.begin(),ans.end());
    int p=ans[(int)(n/2)],all=0;
    for(int i=0;i<n;i++)
    {
        all += abs(ans[i]-p);
    }
    cout<<all<<endl;
    return 0;
}