    #include<iostream>
    #include<unordered_map>
    using namespace std;
    #define MAX_N 5000
    int dp[MAX_N+5],arr[MAX_N+5];
    int binary_find(int n,int len)
    {
        int r=0,l=len,mid;
        while(r<l)
        {
            mid= (l+r+1)/2;
            if(n > arr[mid]) r=mid;
            else l=mid - 1;
        }
        return r;
    }
    int main()
    {
        int n,ans = 0;
        cin>>n;
        arr[0] = -1;
        for(int i=1,a;i<=n;i++)
        {
            cin>>a;
            int len = binary_find(a,ans);
            dp[i] = len + 1;
            arr[len + 1] = a;
            ans = max(ans , dp[i]);
        }
        cout<<ans<<endl;
        return 0;
    }