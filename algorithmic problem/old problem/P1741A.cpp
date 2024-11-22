#include<iostream>
    #include<vector>
    #include<string>
    using namespace std;
    int cnt(char a)
    {
        if(a=='L') return 3;
        if(a=='M') return 2;
        if(a=='S') return 1;
        return 0;
    }
    int main()
    {
        int t;
        cin>>t;
        vector<string> a1,b1;
        for(int i=0;i<t;i++)
        {
            string a3,b3;
            cin>>a3>>b3;
            a1.push_back(a3);
            b1.push_back(b3);
        }
        for(int i=0;i<t;i++)
        {
            string a=a1[i],b=b1[i];
            int a_end=cnt(a[a.size()-1]),b_end=cnt(b[b.size()-1]);
            if(a_end>b_end) 
            {
                cout<<">"<<endl;
                continue;
            }
            if(a_end<b_end) 
            {
                cout<<"<"<<endl;
                continue;
            }
            if(a_end==b_end)
            {
                if(a.size()==b.size()) 
                {
                    cout<<"="<<endl;
                    continue;
                }
                switch(a_end)
                {
                    case 1:
                    {
                        if(a.size()>b.size()) cout<<"<"<<endl;
                        else cout<<">"<<endl;
                    }break;
                    case 3:
                    {
                        if(a.size()>b.size()) cout<<">"<<endl;
                        else cout<<"<"<<endl;
                    }break;
                }
            }
        }
        return 0;
    }