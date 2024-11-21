#include<iostream>
using namespace std;

#define L(ind) (tree[ind].lchild)
#define R(ind) (tree[ind].rchild)
#define C(ind) (tree[ind].c)

#define MAX_N 10000
int n,m,root=1;
int a[MAX_N+5];

struct Node
{
    int c,lchild,rchild;
}tree[2*MAX_N+5];

void up(int ind)
{
    C(ind)=max(C(L(ind)),C(R(ind)));
    return;
}
int p=1;
int getNewchild()
{
    return ++p;
}
void build_tree(int ind,int l,int r)
{
    if(l==r)
    {
        C(ind)=a[l];
        return;
    }
    int mid=(l+r)/2;
    L(ind)=getNewchild();
    R(ind)=getNewchild();
    build_tree(L(ind),l,mid);
    build_tree(R(ind),mid+1,r);
    up(ind);
    return;
}

void modify(int ind,int l,int r,int x,int y)
{
    if(l==r){
        C(ind)=y;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) modify(L(ind),l,mid,x,y);
    else modify(R(ind),mid+1,r,x,y);
    up(ind);
    return;
}

int query(int ind,int l,int r,int x,int y)
{
    if(x<=l && r<=y) return C(ind);
    int mid=(l+r)/2;
    int a,b;
    if(x<=mid) a=query(L(ind),l,mid,x,y);
    if(y>=mid+1) b=query(R(ind),mid+1,r,x,y);
    return max(a,b);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build_tree(root,1,n);
    for(int i=1,x,b,c;i<=m;i++)
    {
        cin>>x>>b>>c;
        switch(x)
        {
            case 1:
            {
                if(b>c) break;
                modify(root,1,n,b,c);
            }break;
            case 2:
            {
                if(b>c)
                {
                    cout<<-2147483648<<endl;
                    break;
                }
                cout<<query(root,1,n,b,c)<<endl;
            }break;
        }
    }
    return 0;
}