#include<iostream>
using namespace std;
#define L(ind) (ind*2)
#define R(ind) (ind*2+1)
#define T(ind) (tree[ind].tag)
#define S(ind) (tree[ind].sum)
#define CNT(ind) (tree[ind].r-tree[ind].l+1)
struct Node
{
    int sum,tag,l,r;
}tree[40005];
int a[10005];
int n,m;
void up(int ind)
{
    S(ind)=S(R(ind))+S(L(ind));
    return;
}
void Down(int ind)
{
    if(T(ind)==0) return;
    T(L(ind))+=T(ind);
    T(R(ind))+=T(ind);
    S(L(ind))+=CNT(L(ind))*T(ind);
    S(R(ind))+=CNT(R(ind))*T(ind);
    T(ind)=0;
    return;
}
void buildTree(int ind,int l,int r)
{
    tree[ind].l=l,tree[ind].r=r,tree[ind].tag=0;;
    if(l==r){
        tree[ind].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    buildTree(ind*2,l,mid);
    buildTree(ind*2+1,mid+1,r);
    up(ind);
    return;
}

void modify(int ind,int x,int y,int z)
{
    if(tree[ind].l>=x && tree[ind].r<=y){
        S(ind)+=CNT(ind)*z;
        T(ind)+=z;
        return;
    }
    int mid=(tree[ind].l+tree[ind].r)/2;
    Down(ind);
    if(x<=mid) modify(ind*2,x,y,z);
    if(y>=mid+1) modify(ind*2+1,x,y,z);
    up(ind);
    return;
}
int query(int ind,int x,int y)
{
    if(x<=tree[ind].l && tree[ind].r<=y) return S(ind);
    int mid=(tree[ind].l+tree[ind].r)/2;
    int ans=0;
    Down(ind);
    if(x<=mid) ans+=query(L(ind),x,y);
    if(y>=mid+1) ans+=query(R(ind),x,y);
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    buildTree(1,1,n);
    for(int i=1,k,b,c,d;i<=m;i++)
    {
        cin>>k;
        switch(k)
        {
            case 1:
            {
                cin>>b>>c>>d;
                if(b>c) break;
                modify(1,b,c,d);
            }break;
            case 2:
            {
                cin>>b>>c;
                if(b>c) 
                {
                    cout<<0<<endl;
                    break;
                }
                cout<<query(1,b,c)<<endl;
            }break;
        }
    }
    return 0;
}