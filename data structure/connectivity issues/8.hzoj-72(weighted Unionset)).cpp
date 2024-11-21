//https://oj.haizeix.com/problem/72


//计算每一个权值的时候,我们用到的是矢量计算
#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 10000
int per[MAX_N+5]={0};
class Weighted_Unionset
{
    public:
    Weighted_Unionset(int n):fa(n+1),val(n+1)
    {
        for(int i=0;i<n;i++) {
            fa[i]=i;
            val[i]=0;
        }
    }
    int get(int x)
    {
        if(fa[x] == x) return x;//如果是根节点,就不需要路径压缩了
        int root = get(fa[x]);//获得根节点坐标
        val[x]=val[x] + val[fa[x]];//更改权值
        return fa[x] = root;//把当前值挂到根节点下面
    }
    void merge(int a,int b,int t)
    {
        int aa=get(a),bb=get(b);
        if(aa==bb) return;
        fa[aa]=bb;
        val[aa]=t-val[a]+val[b];
    }
    vector<int> fa,val;
};
int main()
{
    int n,m;
    cin>>n>>m;
    Weighted_Unionset u(n);
    for(int i=1,a,b,c;i<=m;i++)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
            u.merge(b,c,2);
        }
        else
        {
            if(u.get(b)!=u.get(c)) cout<<"Unknown"<<endl;
            else 
            {
                switch((u.val[b]-u.val[c]%3+3)%3)
                {
                    case 0: printf("Tie\n");break;
                    case 1: printf("Loss\n");break;
                    case 2: printf("Win\n");break;
                }
            }
        }
    }
    return 0;
}