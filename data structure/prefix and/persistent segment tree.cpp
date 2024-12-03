#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 30000000

int n,m;
int a[1000005],root[1000005];
struct Node
{
    int c,lchild,rchild;
}tree[MAX_N+5];
int node_cnt=0;
int build_tree(int l,int r)
{
    int ind=++node_cnt;
    if(l==r)
    {
        tree[ind].c=a[l];
        return ind;
    }
    int mid=(l+r)/2;
    tree[ind].lchild=build_tree(l,mid);
    tree[ind].rchild=build_tree(mid+1,r);
    return ind;
}
int clone(int ind)
{
    node_cnt+=1;
    tree[node_cnt]=tree[ind];
    return node_cnt;
}
int modify(int ind,int l,int r,int x,int y)
{
    ind=clone(ind);
    if(l==r)
    {
        tree[ind].c=y;
        return ind;
    }
    int mid=(l+r)/2;
    if(x<=mid) tree[ind].lchild=modify(tree[ind].lchild,l,mid,x,y);
    else tree[ind].rchild=modify(tree[ind].rchild,mid+1,r,x,y);
    return ind;
}

int query(int ind,int l,int r,int x)
{
    if(l==r)
    {
        return tree[ind].c;
    }
    int mid=(l+r)/2;
    if(x<=mid) return query(tree[ind].lchild,l,mid,x);
    else  return query(tree[ind].rchild,mid+1,r,x);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    root[0]=build_tree(1,n);
    
    for(int i=1,v,x,b,c;i<=m;i++)
    {
        scanf("%d%d%d",&v,&x,&b);
        if(x==1)
        {
            scanf("%d",&c);
            root[i]=modify(root[v],1,n,b,c);
        }
        else 
        {
             cout<<query(root[v],1,n,b)<<endl;
                root[i]=root[v];
        }
    }
    return 0;
}