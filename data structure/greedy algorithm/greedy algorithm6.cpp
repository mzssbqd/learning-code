#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Point
{
    public:
    double l;
    double r;
};
double distance(double y,double d)
{
    return sqrt(d*d-y*y);
}
int main()
{
    double n,d,x,y;
    cin>>n>>d;
    vector<Point> arr(n);
    for(int i=0;i<n;i++) 
    {
        cin>>x>>y;
        double dis=distance(y,d);
        if(y>d)
        {
            cout<<-1<<endl;
            return 0;
        }
        arr[i].l=x-dis;
        arr[i].r=x+dis;
    }
    sort(arr.begin(),arr.end(),[&](Point i,Point j)->bool
    {
        //if(i.r==j.r) return i.l<j.l;
        return i.r<j.r;
    });
    double pos=arr[0].r,cnt=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i].l>pos)
        {
            cnt+=1;
            pos=arr[i].r;
        }
    }
    cout<<cnt<<endl;
    return 0;
}