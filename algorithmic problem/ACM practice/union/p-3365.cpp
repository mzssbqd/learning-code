//https://hydro.ac/d/AHUACM2024/p/P3367

#include<iostream>
#include<vector>
using namespace std;
class Unionset
{
    public:
    Unionset(int n):fa(n+1)
    {
        for(int i=0;i<=n;i++) fa[i]=i;
    }
    int get(int x)
    {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a,int b)
    {
        fa[get(a)] = get(b);
    }
    vector<int> fa;
};
int main()
{
    int n,m;
    cin>>n>>m;
    Unionset u(n);
    for(int i=0,z,x,y;i<m;i++)
    {
        cin>>z>>x>>y;
        if(z == 1) u.merge(x,y);
        else 
        {
            if(u.get(x) == u.get(y)) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}