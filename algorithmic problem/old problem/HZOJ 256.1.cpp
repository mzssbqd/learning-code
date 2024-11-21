#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_N 1000
int a[MAX_N+5],b[MAX_N+5];
vector<int> ind(MAX_N+5);
class Bigint: public vector<int>
{//1234:{4,3,2,1}
    public:
    Bigint(int x)
    {
        this->push_back(x);
        proccess_digit();
    }
    void proccess_digit()
    {
        for(int i=0;i<(int)this->size();i++)
        {
            if(at(i)<10) continue;
            if(i+1==(int)size()) this->push_back(0);
            at(i+1)+=at(i)/10;
            at(i)=at(i)%10;
        }
        while(size() > 1 && at(size()-1)==0) this->pop_back();
        return;
    }
    void operator*=(int x)
    {
        for(int i=0;i<(int)size();i++) at(i)*=x;
        proccess_digit();
        return;
    }
    bool operator>(const Bigint& x) const{
        if(size() != x.size()) return this->size()>x.size();
        for(int i=size()-1;i>=0;i--) 
        {
            if(at(i)!=x[i]) return at(i)>x[i];
        }
        return false;
    }
    Bigint operator/(int x)
    {
        Bigint ret(*this);
        int y=0;
        for(int i=size()-1;i>=0;i--)
        {
            y=y*10+at(i);
            ret[i]=y/x;
            y%=x;
        }
        ret.proccess_digit();
        return ret;
    }
};
ostream &operator<<(ostream &out,const Bigint &x)
{
    for(int i=x.size()-1;i>=0;i--)
    {
        out<<x[i];
    }
    return out;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        ind[i]=i;
    }
    sort(ind.begin()+1,ind.begin()+n+1,[&](int i,int j)->bool
    {
        return a[i]*b[i]<a[j]*b[j];
    });
    Bigint p=a[0],ans=0,temp=0;//temp:正确的数据类型比较
    for(int i=1;i<=n;i++)
    {
        temp=p/b[ind[i]];
        if(temp>ans) ans=temp;
        p*=a[ind[i]];
    }
    cout<<ans<<endl;
    return 0;
} 