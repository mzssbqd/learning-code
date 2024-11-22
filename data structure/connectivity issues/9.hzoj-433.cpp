#include<iostream>
#include<vector>
#include<unordered_map>
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
        return fa[x] = (fa[x]==x ? x: get(fa[x]));
    }
    void merge(int a,int b)
    {
        fa[get(a)]=get(b);
        return;
    }
    vector<int> fa;
};
struct Data
{
    int i,j,e;
};

void solve(int n)
{
    Unionset u(2*n);
    vector<Data> arr(n);
    unordered_map<int,int> m;
    int cnt=0;
    for(int a=0;a<n;a++)
    {
        scanf("%d %d %d",&arr[a].i,&arr[a].j,&arr[a].e);
        if(m.find(arr[a].i) == m.end()) m[arr[a].i]=(cnt++);
        if(m.find(arr[a].j) == m.end()) m[arr[a].j]=(cnt++);
    }
    for(int k=0;k<n;k++)
    {
        if(arr[k].e == 1) u.merge(m[arr[k].i],m[arr[k].j]); 
    }
    int flag=0;
    for(int k=0;k<n;k++)
    {
        if(arr[k].e == 0){
            if(u.get(m[arr[k].i]) == u.get(m[arr[k].j])) 
            {
                flag=1;
                break;
            }
        }
    }
    printf("%s\n",(flag == 1 ? "NO" : "YES"));
    return;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        solve(n);
    }
    float a;
    return 0;
}