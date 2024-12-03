#include<iostream>
using namespace std;
#define MAX_N 10000
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
int n,m;
int num[MAX_N+5],tree[MAX_N*4+5];//1

int update(int ind)
{
    tree[ind]=max(tree[ls(ind)],tree[rs(ind)]);
    //tree[ind] = tree[ls(ind)] + tree[rs(ind)];
    return 0;
}
void build_tree(int p,int pl,int pr)
{
    if(pl == pr) { tree[p] = num[pl]; return ;}
    int mid=(pl + pr) >> 1;
    build_tree(ls(p), pl, mid);
    build_tree(rs(p), mid + 1, pr);
    update(p);
    return;  
}
//单点修改
void modify(int p,int pl,int pr,int k,int x)
{
    if(pr == pl) { tree[pl] = x; return ;}
    int mid = (pl + pr) >> 1;
    if(mid >= k) modify(ls(p),pl,mid,k,x);
    else modify(rs(p),mid+1,pr,k,x);
    update(p);
    return ;
}
//query node
int query(int p,int pl,int pr,int L,int R)
{
    if(L <= pl && pr <= R) return tree[p];
    int mid=(pl+pr) >> 1;
    int ans=-2147483648;
    /*
        L      mid          R
    */
    if(L <= mid) ans=max(ans, query(ls(p), pl, mid, L, R)); 
    if(R >= mid + 1) ans=max(ans, query(rs(p), mid+1, pr, L, R));
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    build_tree(1,1,n);
    for(int i=1,a,b,c;i<=m;i++)
    {
        cin>>a>>b>>c;
        switch(a)
        {
            case 1:
            {
                if(b>c) break;
                modify(1, 1, n, b, c);
            }break;
            case 2:
            {
                if(b > c) cout<<"-2147483648"<<endl;
                else
                {
                    cout<<query(1, 1, n, b, c)<<endl;
                }
            }break; 
        }
    }
    return 0;
}