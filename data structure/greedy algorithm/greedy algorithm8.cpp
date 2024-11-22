#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Cow
{
    public:
    int l;
    int r;
};
class type
{
    public:
    int size;
    int num;
};
int main()
{
    int c,l;
    cin>>c>>l;
    vector<Cow> cow(c);
    vector<type> arr(l);
    for(int i=0;i<c;i++)
    {
        cin>>cow[i].l>>cow[i].r;
    }
    for(int i=0;i<l;i++)
    {
        cin>>arr[i].size>>arr[i].num;
    }
    sort(cow.begin(),cow.end(),[&](Cow i,Cow j)->bool
    {
        if(i.l==j.l) return i.r<j.r;
        return i.l<j.l;
    });
    sort(arr.begin(),arr.end(),[&](type i,type j)->bool
    {
        return i.size<j.size;
    });
    int tot=0;
    for(int i=0;i<c;i++)
    {
        int flag=0;
        for(int j=0;j<l;j++)
        {
            if(arr[j].num == 0) continue;
            if(arr[j].size>=cow[i].l && arr[j].size<=cow[i].r) 
            {
                arr[j].num-=1;
                flag=1;
                break;
            }
        }
        tot+=flag;
    }
    cout<<tot<<endl;
    return 0;
}