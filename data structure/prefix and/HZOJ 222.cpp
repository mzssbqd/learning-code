    #include<iostream>
    using namespace std;
    #define MAX_N 10000
    int n,m;
    int num[MAX_N+5],tree[MAX_N*4+5];//1

    //build segment_tree
    int update(int ind)
    {
        tree[ind]=max(tree[ind*2],tree[ind*2+1]);
        return 0;
    }
    void build_tree(int ind,int l,int r)
    {
        if(l==r)
        {
            tree[ind]=num[l];
            return;
        }
        int mid=(l+r)/2;
        build_tree(ind*2,l,mid);
        build_tree(ind*2+1,mid+1,r);
        update(ind);
        return; 
    }


    //modify segment_tree
    void modify(int ind,int l,int r,int x,int y)
    {
        if(l==r)
        {
            tree[ind]=y;
            return;
        }
        int mid=(l+r)/2;
        if(mid>=x) modify(ind*2,l,mid,x,y);
        else modify(ind*2+1,mid+1,r,x,y);
        update(ind);
        return;
    }

    //query node
    int query(int ind,int l,int r,int x,int y)
    {
        if(x<=l && r<=y) return tree[ind];
        int mid=(l+r)/2;
        int ans=-2147483648;
        if(l<=y && x<=mid) ans=max(ans,query(ind*2,l,mid,x,y));
        if(mid+1<=y && x<=r) ans=max(ans,query(ind*2+1,mid+1,r,x,y));
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
        for(int i=1,a,b,c,d;i<=m;i++)
        {
            cin>>a>>b>>c;
            switch(a)
            {
                case 1:
                {
                    cin>>d;
                    if(b>c) break;
                    modify(1,1,n,b,c);
                }break;
                case 2:
                {
                    if(b>c) cout<<"-2147483648"<<endl;
                    else
                    {
                        cout<<query(1,1,n,b,c)<<endl;
                    }
                }break;
            }
        }
        return 0;
    }