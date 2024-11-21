    #include<iostream>
    #include<string>
    using namespace std;
    int main()
    {
        int n;
        cin>>n;
        string ans,str,temp;
        for(int i=n,a;i>=1;i--)
        {
            cin>>a;
            if(a==0) continue;
            temp=to_string(a);
            if(a==1 || a==-1) temp.pop_back();
            if(a>0 && i!=n) str="+"+temp+"x^"+to_string(i);
            else str=temp+"x^"+to_string(i);
            ans+=str;
        }
        int a;
        cin>>a;
        if(n==0) cout<<to_string(n)<<endl;
        if(a>0){
            ans+="+"+to_string(a);
        }
        else ans+=to_string(a);
        cout<<ans<<endl;
        return 0;
    }