#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int c;
    cin>>c;
    vector<int> b(c),e(c),ind(c),time;
    for(int i=0;i<c;i++)
    {
        cin>>b[i]>>e[i];
        ind[i]=i;
    }
    stable_sort(ind.begin(),ind.end(),[&](int i,int j)->bool
    {
        return b[i]<b[j];
    });
    int cnt=0,pos=-1;
    for(int i=0;i<c;i++)
    {
        int j=0;
        for(;j<time.size();j++)
        {
            if(time[j]<b[ind[i]])
            {
                time[j]=e[ind[i]];
                b[ind[i]]=j;
                pos=j;
                break;
            }
        }
        if(pos==-1)
        {
            time.push_back(e[ind[i]]);
            b[ind[i]]=j;
        }
        pos=-1;
    }
    cout<<time.size()<<endl;
    for(auto x:b) cout<<x+1<<endl;
    return 0;
}