    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    typedef long long ll;
    class Weighted_Unionset
    {
        public:
        Weighted_Unionset(int n):fa(n+1),val(n+1)
        {
            for(int i=0;i<=n;i++) 
            {
                fa[i]=i;
                val[i]=0;//1
            }
        }
        int get(int x){
            if(fa[x] == x) return x;
            int root=get(fa[x]);
            val[x]=(val[x]+val[fa[x]])%2;//3
            return fa[x] = root;
        }
        void merge(int a,int b,int t)
        {
            int aa=get(a),bb=get(b);
            if(aa == bb) return; 
            fa[aa] = bb;
           val[bb]=(t-val[a]+val[b]+2)%2; //2
            return;
        }
        vector<int> fa,val; 
    };
    struct Data
    {
        int a,b;
        ll c;
    };
    int main(){
        int n,m;
        cin>>n>>m;
        Weighted_Unionset u(n);
        vector<Data> v(m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %lld",&v[i].a,&v[i].b,&v[i].c);
        }
        sort(v.begin(),v.end(),[&](const Data &a,const Data &b)->bool
        {
            return a.c>b.c;
        });
        ll ans=0;
        for(int i=0;i<m;i++)
        {
            int a=v[i].a,b=v[i].b;
            ll c=v[i].c;
            if(u.get(a) == u.get(b))
            {
                if((u.val[a]+u.val[b])%2 == 0) 
                {
                    ans=c;
                    break;
                }
            }
            else 
            {
                u.merge(a,b,1);
            }
        }
        cout<<ans<<endl;
        return 0;
    }