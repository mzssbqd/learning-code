#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Apple
{
    public:
    int high;
    int s;
};
int main()
{
    int n,cnt,a,b;
    cin>>n>>cnt;
    cin>>a>>b;
    a=a+b;
    vector<Apple> v;
    for(int i=0;i<n;i++)
    {
        Apple temp;
        cin>>temp.high>>temp.s;
        if(temp.high<=a) v.push_back(temp);
    }
    sort(v.begin(),v.end(),[&](Apple i,Apple j)->bool
    {
        return i.s<j.s;
    });
    n=v.size();
    int flag=0;
    for(int i=0;i<n;i++) 
    {
        if(cnt>=v[i].s)
        {
             cnt-=v[i].s,flag+=1;
        }
        else break;
    }
    cout<<flag<<endl;
    return 0;
}