#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,flag=0;
    cin>>n;
    vector<string> ops(n),s;
    string target;
    for(int i=0;i<n;i++)cin>>ops[i];
    cin>>target;
    for(int i=0;i<n;i++)
    {
        if(target==ops[i])
        {
            s.push_back(ops[i]);
            flag=true;
            break;
        }
        if(ops[i]=="return") s.pop_back();
        else s.push_back(ops[i]);
    }
    if(flag)
    {
        for(int i=0;i<s.size();i++)
        {
            if(i)cout<<"->";
            cout<<s[i];
        }
    }
    else cout<<"NOT REFERENCED"<<endl;
    return 0;
}