    //https://hydro.ac/d/AHUACM2024/p/P3958

    #include<iostream>
    #include<vector>
    #include<math.h>
    using namespace std;
    typedef long long ll;
    class Unionset
    {
        public:
        Unionset(int n):fa(n+1)
        {
            for(int i=0;i<=n;i++)
            {
                fa[i]=i;
            }
        }
        int get(int x)
        {
            return fa[x] = (fa[x] == x ? x : get(fa[x]));
        }
        void merge(int a,int b)
        {
            fa[get(a)]=get(b);
            return;
        }
        vector<int> fa;
    };
    struct point
    {
        ll x,y,z;
        int ind;
    };
    ll distance(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2)
    {
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
    }
    void solve(int n,int h,int r)
    {
        Unionset u(n);
        vector<point> arr(n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld %lld",&arr[i].x,&arr[i].y,&arr[i].z);
            arr[i].ind=i;
        }
        vector<int> b,t;
        for(int i=0;i<n;i++)
        {
            if(arr[i].z<=r) b.push_back(arr[i].ind);
            if(h-arr[i].z<=r) t.push_back(arr[i].ind);
            for(int j=i+1;j<n;j++)
            {
                if(sqrt(distance(arr[i].x,arr[i].y,arr[i].z,arr[j].x,arr[j].y,arr[j].z))<=2*r)
                {
                    u.merge(arr[i].ind,arr[j].ind);
                }
            }
        }
        int flag=0;
        for(int i=0,I=b.size();i<I;i++)
        {
            for(int j=0,J=t.size();j<J;j++)
            {
                // cout<<"b.size():"<<b.size()<<endl;
                // cout<<"i: "<<i<<"j:"<<j<<endl;
                // cout<<b[i]<<" "<<t[j]<<endl;
                if(u.get(b[i])==u.get(t[j]))
                {
                    flag=1;
                    break;
                }
            }
            if(flag == 1) break;
        }
        if(flag == 1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return;
    }
    int main()
    {
        ll T,a,b,c;
        cin>>T;
        while(T--)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            solve(a,b,c);
        }
        return 0;
    }