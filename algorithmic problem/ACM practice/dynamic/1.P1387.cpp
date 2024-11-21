    #include<iostream>
    using namespace std;
    #define MAX_N 100
    int arr[MAX_N+5][MAX_N+5]; 
    int n,m;


    int SUM(int i,int j,int x)
    {
        return arr[i][j]-arr[i-x][j]-arr[i][j-x]+arr[i-x][j-x];
    }
    bool check(int x)
    {
        for(int i=x;i<=n;i++)
        {
            for(int j=x;j<=m;j++)
            {
                if(SUM(i,j,x) == x*x) return 1;
            }
        }
        return 0;
    }
    int binary_find(int max_n)
    {
        int r=1,l=max_n,mid;
        while(r<l)
        {
            mid=(l+r+1)>>1;
            if(check(mid) == 1) r=mid;
            else l=mid-1;
        }
        return r;
    }
    int main()
    {
    
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>arr[i][j];
                arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            }
        }
        int max_n=max(m,n);
        cout<<binary_find(max_n)<<endl;
        return 0;
    }