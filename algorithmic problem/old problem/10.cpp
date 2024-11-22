#include<iostream>
#include<set>
using namespace std;
int main()
{
    int N,m;
    set<int> x;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>m;
        x.insert(m);
    }
    cout<<x.size()<<endl;
    for(auto it=x.begin();it!=x.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}